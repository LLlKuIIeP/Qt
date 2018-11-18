//Листинг 31.2
#include <QApplication>
#include "contextmenu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ContextMenu cntMenu;
    cntMenu.show();

    return app.exec();
}
