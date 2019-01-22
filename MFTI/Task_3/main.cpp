//Task 3
#include <QApplication>
#include "widget.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(1030, 500);
    w.show();

    return a.exec();
}
