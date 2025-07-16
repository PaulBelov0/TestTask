#include "services/app_manager.h"

int main(int argc, char *argv[])
{
#if __WIN32
    setlocale(LC_ALL, "Russian");
#endif

    AppManager app;

    return app.start(argc, argv);
}
