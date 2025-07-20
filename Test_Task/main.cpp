#include "services/app_manager.h"

#ifdef __WIN32__
#include <windows.h>
#endif

int main(int argc, char *argv[])
{
#if __WIN32__
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    AppManager app;

    return app.start(argc, argv);
}
