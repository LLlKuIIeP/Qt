//Листинг 28.1
#include <QApplication>
#include "myprogram.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyProgram myProgram;
    myProgram.show();

    return app.exec();
}
