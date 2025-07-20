#ifndef ARCHIVER_PIPELINE_H
#define ARCHIVER_PIPELINE_H

#include <QObject>

class ArchiverPipeline : public QObject
{
    Q_OBJECT
public:
    explicit ArchiverPipeline(QObject *parent = nullptr);

signals:
    void onDirectoryWrong();
    void onFileReaded();
    void onFileSaved();

signals:
};

#endif // ARCHIVER_PIPELINE_H
