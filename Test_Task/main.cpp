#include "services/app_manager.h"

#ifdef __WIN32__
#include <windows.h>
#endif

int main(int argc, char *argv[])
{
#if __WIN32__
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "Russian");
#endif

    AppManager app;

    return app.start(argc, argv);
}
