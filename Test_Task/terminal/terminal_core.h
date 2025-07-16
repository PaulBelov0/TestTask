#ifndef TERMINAL_CORE_H
#define TERMINAL_CORE_H

#include <iostream>
#include <string>

#include <QObject>
#include <QDebug>

#include "services/archive_manager.h"

class TerminalCore : public QObject
{
    Q_OBJECT
public:
    explicit TerminalCore(QObject *parent = nullptr);
    int start();

private:
    std::string m_path;

    QScopedPointer<ArchiveManager> m_archiveManager;
};

#endif // TERMINAL_CORE_H
