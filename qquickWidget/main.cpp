#include "quickwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuickWidget w;
    w.show();

    return a.exec();
}
