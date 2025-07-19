#include "terminal_core.h"

TerminalCore::TerminalCore(QObject *parent)
    : QObject{parent}
    , m_archiveManager(new ArchiveManager(this))
    , m_terminalProcess(new QProcess(this))
{
    /*m_path = "/home/belov-paul/Загрузки/Telegram Desktop/operator.zip"*/;

    forceTerminal();
}

int TerminalCore::start()
{

    while(!m_terminalProcess->isOpen())
    {
        qDebug() << "Not Open";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

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
#ifdef __WIN32__
    if (QProcess::execute("where", QStringList() << "cmd.exe") == 0)
    {
        m_terminalProcess->start(
            "wt.exe",
            QStringList() << "cmd.exe" << "/k" << "start" << QCoreApplication::applicationFilePath()
            );
    }
#elif __linux__
    if (!isatty(fileno(stdout)))
    {
        QString terminal = "x-terminal-emulator";

        QString command = QString("\"%1\"; bash -i").arg(QCoreApplication::applicationFilePath());

        m_terminalProcess->startDetached(terminal, {"-e", "bash", "-c", command});

        // execl("/bin/bash", "/bin/bash", "-i");
    }
#endif
}
