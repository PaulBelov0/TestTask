#include "terminal_core.h"

TerminalCore::TerminalCore(QObject *parent)
    : QObject{parent}
    , m_archiveManager(new ArchiveManager(this))
{
    /*m_path = "/home/belov-paul/Загрузки/Telegram Desktop/operator.zip"*/;
}

int TerminalCore::start()
{

    forceTerminal();
    std::cout << "Введите путь к файлу '*.zip':    ";
    std::getline(std::cin, m_path);
    std::cout << "User input:   " << m_path;
    if (m_path == "")
        return 0;

    m_archiveManager->setPath(m_path);

    return 0;
}

void TerminalCore::forceTerminal()
{
#ifdef __WIN32
    qDebug() << "start";
    system("start PowerShell.exe");
#elif __linux__
    if (!isatty(fileno(stdout)))
    {
        QString terminal = "x-terminal-emulator";

        QString command = QString("\"%1\"; bash -i").arg(QCoreApplication::applicationFilePath());

        QProcess::startDetached(terminal, {"-e", "bash", "-c", command});

        // execl("/bin/bash", "/bin/bash", "-i");
    }
#endif
}
