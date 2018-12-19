//Листинг 52.1
#include <QApplication>
#include "turtleworkarea.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TurtleWorkArea turtleWorkArea;
    turtleWorkArea.show();

    return app.exec();
}
