#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#endif

#ifdef __WIN32
#include <windows.h>
#endif

#include <iostream>

#include <QObject>
#include <QApplication>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFileDialog>
#include <QResource>
#include <QProcess>
#include <QSharedPointer>

#include "archive_manager.h"
#include "ui/main_window.h"

enum class LaunchConfig;

class AppManager : public QObject
{
public:
    AppManager(QObject* parent = nullptr);

    int start(int argc, char* argv[]);


private:

    void setPath(LaunchConfig type);
    void forceTerminal();
    LaunchConfig getConfiguration();

private:
    QString m_path;
    QSharedPointer<QJsonDocument> m_cfg;
};

enum class LaunchConfig
{
    Gui,
    Cmd,
    Tests,
    ERROR
};

#endif // APP_MANAGER_H
