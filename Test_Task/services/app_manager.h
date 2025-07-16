#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#endif

#ifdef __WIN32
#include <windows.h>
#include <shlwapi.h>
#include <shlobj.h>
#endif

#include <iostream>
#include <stdio.h>

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
#include "terminal/terminal_core.h"

enum class LaunchConfig;

class AppManager : public QObject
{
    Q_OBJECT
public:
    AppManager(QObject* parent = nullptr);

    int start(int argc, char* argv[]);

private:
    void setPath();
    void forceTerminal();
    LaunchConfig getConfiguration();

signals:
    void onUserNullPath();

private:
    QString m_path;
    LaunchConfig m_launchConfig;
    QSharedPointer<QJsonDocument> m_cfg;
};

enum class LaunchConfig
{
    Gui,
    Cmd,
    Tests,
    ERR
};

#endif // APP_MANAGER_H
