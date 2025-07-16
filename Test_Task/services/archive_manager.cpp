#include "archive_manager.h"

ArchiveManager::ArchiveManager(QString& path, QObject* parent)
    : QObject(parent)
{
    m_targetWord = "secret";
    m_path = path;
}

ArchiveManager::ArchiveManager(QObject* parent)
    : QObject(parent)
{
    m_targetWord = "secret";
}

void ArchiveManager::setPath(std::string &path)
{
    m_path = QString::fromStdString(path);
}

void ArchiveManager::processZip() {
    QFile file(m_path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "File open Error!";
        return;
    }

    qint64 eocdPos = findEOCD(file);
    if (eocdPos == -1) {
        qDebug() << "It's not ZIP";
        return;
    }

    QList<ZipEntry> entries = readCentralDirectory(file, eocdPos);
    for (QList<ZipEntry>::iterator it = entries.begin(); it != entries.end(); ++it) {
        if (!it->filename.endsWith(".txt")) continue;

        QByteArray data = readUncompressedFile(file, it);
        if (data.contains(m_targetWord.toUtf8())) {
            qDebug() << "File:" << it->filename;
            // Написать сохранение в нужную папку           //todo
        }
    }
}

qint64 ArchiveManager::findEOCD(QFile &file)
{
    const quint32 EOCD_SIGNATURE = 0x06054b50;
    const qint64 maxSearchSize = 1024 * 1024; // Searchging in last 1 МБ of file

    file.seek(qMax(file.size() - maxSearchSize, 0LL));

    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::LittleEndian);

    while (!stream.atEnd())
    {
        quint32 signature;
        stream >> signature;
        if (signature == EOCD_SIGNATURE)
        {
            return file.pos() - 4; // Return EOCD position
        }
    }
    return -1;
}

QList<ZipEntry> ArchiveManager::readCentralDirectory(QFile &file, qint64 eocdPos)
{
    QList<ZipEntry> entries;
    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::LittleEndian);

    file.seek(eocdPos + 10);
    quint16 numEntries;
    stream >> numEntries;

    file.seek(eocdPos + 16);
    quint32 cdOffset;
    stream >> cdOffset;
    file.seek(cdOffset);

    for (int i = 0; i < numEntries; ++i)
    {
        quint32 signature;
        stream >> signature;
        if (signature != 0x02014b50) break; // Central Title

        file.seek(file.pos() + 4); //Skip version
        quint16 flags, compressionMethod;
        stream >> flags >> compressionMethod;

        file.seek(file.pos() + 10); //Skip date/time and crc

        quint32 compressedSize, uncompressedSize;
        stream >> compressedSize >> uncompressedSize;

        quint16 filenameLen, extraLen, commentLen;
        stream >> filenameLen >> extraLen >> commentLen;

        file.seek(file.pos() + 8); //skip disk and attributes

        quint32 localHeaderOffset;
        stream >> localHeaderOffset;

        QByteArray filename(filenameLen, '\0');
        stream.readRawData(filename.data(), filenameLen);

        file.seek(file.pos() + extraLen + commentLen);

        entries.append({
            QString::fromLatin1(filename),
            compressionMethod != 0,
            compressedSize,
            uncompressedSize,
            localHeaderOffset
        });
    }

    return entries;
}

QByteArray ArchiveManager::readUncompressedFile(QFile &zipFile, QList<ZipEntry>::iterator &entry)
{
    zipFile.seek(entry->localHeaderOffset + 26); // Go to file data

    quint16 filenameLen, extraLen;
    QDataStream(&zipFile) >> filenameLen >> extraLen;

    zipFile.seek(zipFile.pos() + filenameLen + extraLen); // Skip title
    return zipFile.read(entry->compressedSize);
}
