#include "terminal_core.h"

TerminalCore::TerminalCore(QObject *parent)
    : QObject(parent)
    , m_archiveManager(new ArchiveManager(this))
    , m_terminalProcess(new QProcess(this))
{}

int TerminalCore::start()
{
    forceTerminal();


    std::wcout << "привет" << std::endl;
    qDebug() << "вызов TerminalCore::start()";
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

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    qSetMessagePattern("%{file}(%{line}): %{message}");
#else
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

#elif __linux__
    if (!isatty(fileno(stdout)))
    {
        QString terminal = "x-terminal-emulator";

        QString command = QString("\"%1\"; bash -i").arg(QCoreApplication::applicationFilePath());

        m_terminalProcess->startDetached(terminal, {"-e", "bash", "-c", command});
    }
#endif
}
