#include "terminal_core.h"

TerminalCore::TerminalCore(QObject *parent)
    : QObject{parent}
    , m_archiveManager(new ArchiveManager(this))
{
    m_path = "/home/belov-paul/Загрузки/Telegram Desktop/operator.zip";
}

int TerminalCore::start()
{
    std::cout << "Введите путь к файлу '*.zip'" << std::endl;
    std::getline(std::cin, m_path);

    if (m_path == "")
        return 0;

    m_archiveManager->setPath(m_path);

    return 0;
}
