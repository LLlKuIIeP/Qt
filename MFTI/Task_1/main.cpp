
#include <QApplication>
#include <QtCharts>
#include "widget.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(1500, 1000);
    w.show();

    return a.exec();
}
