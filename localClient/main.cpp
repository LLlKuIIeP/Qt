#include "localclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LocalClient w;
    w.show();

    return a.exec();
}
