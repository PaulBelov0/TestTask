#include "services/app_manager.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    AppManager app;

    return app.start(argc, argv);
}
