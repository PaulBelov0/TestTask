#ifndef ARCHIVE_MANAGER_H
#define ARCHIVE_MANAGER_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QDataStream>
#include <QList>
#include <QByteArray>
#include <QDebug>

struct ZipEntry;

class ArchiveManager : public QObject
{
public:
    ArchiveManager(QString& path, QObject* parent);

    void processZip();

    qint64 findEOCD(QFile &file);    // Searching EOCD (End of Central Directory)
    QList<ZipEntry> readCentralDirectory(QFile &file, qint64 eocdPos);
    QByteArray readUncompressedFile(QFile &zipFile, QList<ZipEntry>::iterator &entry);

private:
    QString m_targetWord;
    QString m_path;
};

struct ZipEntry
{
    QString filename;
    bool isCompressed;
    quint32 compressedSize;
    quint32 uncompressedSize;
    quint32 localHeaderOffset;
};

#endif // ARCHIVE_MANAGER_H
