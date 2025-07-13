#include "main_window.h"

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString pathToFile = "";

    char* username = getenv("USER");
    if (!username)
    {
        username = getenv("USERNAME");
    }

#ifdef __linux__

    pathToFile = QFileDialog::getOpenFileName(nullptr, "Select file", "/home/" + QString(username), "*.zip");

#elif __WIN32

    pathToFile = QFileDialog::getOpenFileName(nullptr, "Select file", "C:\Users\" + QString(username) + "\Documents", "*.zip");

#else

    QMessageBox msg;
    msg.setText("Error! Unsupported System");
    msg.exec();
    return 0;

#endif

    if (pathToFile == "")
        return 0;

    MainWindow w(pathToFile);

    w.show();

    return a.exec();
}
