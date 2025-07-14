#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include <QObject>

#include "archive_manager.h"

class AppManager : public QObject
{
public:
    explicit AppManager(QObject* parent = nullptr);

    void setFile(QString pathToFile);

private:
    QString m_path;
};

#endif // APP_MANAGER_H
