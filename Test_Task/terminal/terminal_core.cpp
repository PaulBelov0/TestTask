#include "terminal_core.h"

TerminalCore::TerminalCore(QObject *parent)
    : QObject(parent)
    , m_archiveManager(new ArchiveManager(this))
    , m_terminalProcess(new QProcess(this))
{}

int TerminalCore::start()
{
    forceTerminal();

    std::cout << "Введите путь к файлу '*.zip':    ";
    std::getline(std::cin, m_path);
    std::cout << "User input:   " << m_path << std::endl;
    if (m_path == "")
        return 0;

    m_archiveManager->setPath(m_path);

    emit finished();
    return 0;
}

void TerminalCore::forceTerminal()
{
#ifdef __WIN32__
    AllocConsole();
    freopen("CONIN$", "r", stdin);   // Перенаправляет stdin
    freopen("CONOUT$", "w", stdout); // Перенаправляет stdout
    freopen("CONOUT$", "w", stderr); // Перенаправляет stderr

#elif __linux__
    if (!isatty(fileno(stdout)))
    {
        QString terminal = "x-terminal-emulator";

        QString command = QString("\"%1\"; bash -i").arg(QCoreApplication::applicationFilePath());

        m_terminalProcess->startDetached(terminal, {"-e", "bash", "-c", command});
    }
#endif
}
