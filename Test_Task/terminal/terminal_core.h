#ifndef TERMINAL_CORE_H
#define TERMINAL_CORE_H

#include <iostream>

#include <QObject>

class TerminalCore : public QObject
{
    Q_OBJECT
public:
    explicit TerminalCore(QString& path, QObject *parent = nullptr);
    int start();

private:
    QString m_path;
};

#endif // TERMINAL_CORE_H
