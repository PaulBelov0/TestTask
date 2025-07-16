#include "app_manager.h"

AppManager::AppManager(QObject* parent)
    : QObject(parent)
{
    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Ошибка открытия файла:" << file.errorString();
    }

    m_cfg = QSharedPointer<QJsonDocument>(new QJsonDocument(QJsonDocument::fromJson(file.readAll())));
}

int AppManager::start(int argc, char* argv[])
{
    LaunchConfig launchConfig = getConfiguration();

    if (launchConfig == LaunchConfig::ERR)
        return -1;

    if (launchConfig == LaunchConfig::Gui)
    {
        QApplication a(argc, argv);

        try
        {
            setPath(launchConfig);
        }
        catch (const std::exception& ex)
        {
            return 0;
        }

        MainWindow w(m_path);

        w.show();

        return a.exec();
    }
    if (launchConfig == LaunchConfig::Cmd)
    {
        forceTerminal();

        QCoreApplication ca(argc, argv);

        try
        {
            setPath(launchConfig);
        }
        catch (const std::exception& ex)
        {
            return 0;
        }

        return ca.exec();
    }
    else
        return 0;
}

void AppManager::setPath(LaunchConfig type)
{
    QString pathToFile = "";

    char* username = getenv("USER");
    if (!username)
    {
        username = getenv("USERNAME");
    }

    if (type == LaunchConfig::Gui)
    {
#ifdef __linux__

    pathToFile = QFileDialog::getOpenFileName(nullptr, "Select file", "/home/" + QString(username), "*.zip");

#elif __WIN32
    PWSTR pszPath = nullptr;
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &pszPath);

    if (SUCCEEDED(hr))
    {
        QString documentsPath = QString::fromWCharArray(pszPath);
        CoTaskMemFree(pszPath);

        pathToFile = QFileDialog::getOpenFileName(nullptr, "Select file", documentsPath, "*.zip");
    }
    else
    {
        qDebug() << "Failed to get Documents folder path. HRESULT:" << hr;
        pathToFile = QFileDialog::getOpenFileName(nullptr, "Select file", "C:\\", "*.zip");
    }
#else

    QMessageBox msg;
    msg.setText("Error! Unsupported System");
    msg.exec();
    return 0;

#endif
    }
    else
    {
        pathToFile = "/home/belov-paul/operator.zip";
    }
    if (pathToFile == "")
        throw;
    m_path = pathToFile;

}

LaunchConfig AppManager::getConfiguration()
{
    const QString path = "config.json";

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Ошибка открытия файла:" << file.errorString();
    }

    QJsonObject root = m_cfg->object();
    QJsonObject params = root["launch_params"].toObject();

    bool guiEnabled = params["Gui"].toBool();

    if (guiEnabled)
        return LaunchConfig::Gui;

    bool cmdEnabled = params["Cmd"].toBool();

    if (cmdEnabled)
        return LaunchConfig::Cmd;

    bool testEnabled = params["Test"].toBool();

    if (testEnabled)
        return LaunchConfig::Tests;

    return LaunchConfig::ERR;
}

void AppManager::forceTerminal()
{
#ifdef __WIN32
    if (AttachConsole(ATTACH_PARENT_PROCESS))
    {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
    else if (AllocConsole())
    {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
#elif __linux__
    if (!isatty(fileno(stdout)))
    {
        QProcess::startDetached("x-terminal-emulator", {"-e", "bash", "-c",
                                                          QString("\"%1\"; exec bash").arg(QCoreApplication::applicationFilePath())
                                                       });
    }
#endif
}
