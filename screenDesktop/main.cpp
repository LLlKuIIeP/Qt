//Листинг 35.8
#include <QtWidgets>
#include "grabwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GrabWidget wgt;
    wgt.show();

    return app.exec();
}
