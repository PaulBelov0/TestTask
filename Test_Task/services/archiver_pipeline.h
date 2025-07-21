#ifndef ARCHIVER_PIPELINE_H
#define ARCHIVER_PIPELINE_H

#include <iostream>
#include <string>
#include <filesystem>
#include <tuple>

#include <QObject>
#include <QScopedPointer>

#include "services/archive_manager.h"

class ArchiverPipeline : public QObject
{
    Q_OBJECT
public:
    explicit ArchiverPipeline(QObject *parent = nullptr);

signals:
    void onFileDirectoryWrong();
    void onSaveDirecroryWrong();
    void onFileReaded();
    void onFileSaved();

public slots:
    void setPathToRead(const std::string& path);
    void setPathToSave(const std::string& path);

private:
    bool checkPathToSave(const std::string& path);
    bool isZipFile(const std::filesystem::path& path);
    bool checkPathToRead(const std::string& path);

private:
    QScopedPointer<ArchiveManager> m_archive;
    QString m_pathToSave;
};

#endif // ARCHIVER_PIPELINE_H
