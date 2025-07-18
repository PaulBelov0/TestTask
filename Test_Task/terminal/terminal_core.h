#ifndef TERMINAL_CORE_H
#define TERMINAL_CORE_H

#ifdef __linux__
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#ifdef __WIN32
#include <windows.h>
#include <shlwapi.h>
#include <shlobj.h>
#endif


#include <iostream>
#include <string>
#include <cstdlib>

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QCoreApplication>
#include <QTextStream>

#include "services/archive_manager.h"

class TerminalCore : public QObject
{
    Q_OBJECT
public:
    explicit TerminalCore(QObject *parent = nullptr);
    int start();
    void forceTerminal();

private:
    std::string m_path;

    QScopedPointer<ArchiveManager> m_archiveManager;
    QSharedPointer<QProcess> m_terminalProcess;
};

#endif // TERMINAL_CORE_H
