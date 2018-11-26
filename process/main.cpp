//Листинг 38.1
#include <QtWidgets>
#include "shell.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Shell wgt;
    wgt.show();

    return app.exec();
}
