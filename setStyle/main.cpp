//Листинг 26.2
#include <QApplication>
#include "myapplication.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyApplication myApplication;
    myApplication.show();

    return app.exec();
}
