//Листинг 8.2
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton cmd("Menu");
    QMenu *pmnu = new QMenu(&cmd);
    pmnu->addAction("Item 1");
    pmnu->addAction("Item 2");
    pmnu->addAction("&Quit", &app, SLOT(quit()));

    cmd.setMenu(pmnu);
    cmd.show();

    return app.exec();
}
