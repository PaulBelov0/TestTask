#include "services/app_manager.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russiаn");

    AppManager app;

    return app.start(argc, argv);
}
