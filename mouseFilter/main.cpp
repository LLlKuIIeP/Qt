//Листинг 15.1

#include <QtWidgets>
#include "mousefilter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));  //установка фильтра событий, можно установить сколь угодно фильтров,
    txt.resize(150, 50);                            //последний фильтр будет обрабатываться первым
    txt.show();

    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&lbl));
    lbl.resize(150, 50);
    lbl.show();

    QPushButton cmd("QPushButton");
    cmd.installEventFilter(new MouseFilter(&cmd));
    cmd.resize(150, 50);
    cmd.show();

    return app.exec();
}
