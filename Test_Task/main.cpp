#include "services/app_manager.h"
#include "main_window.h"

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    AppManager app(nullptr);

    return app.start(argc, argv);
}
