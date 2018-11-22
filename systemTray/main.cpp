//Листинг 35.1
#include <QtWidgets>
#include "systemtray.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SystemTray st;
    QApplication::setQuitOnLastWindowClosed(false);

    return app.exec();
}
