#include "terminal_core.h"

TerminalCore::TerminalCore(QString& path, QObject *parent)
    : QObject{parent}
{
    m_path = path;
}

int TerminalCore::start()
{

}
