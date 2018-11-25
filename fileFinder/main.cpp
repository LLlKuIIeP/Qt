//Листинг 36.1
#include <QtWidgets>
#include "filefinder.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FileFinder wgt;
    wgt.show();

    return app.exec();
}
