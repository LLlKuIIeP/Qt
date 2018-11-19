//Листинг 32.1
#include <QApplication>
#include "startdialog.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartDialog startDialog;
    startDialog.show();

    return app.exec();
}
