#include "localserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LocalServer w;
    w.show();

    return a.exec();
}
