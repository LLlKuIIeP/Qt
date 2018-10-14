//Листинг 11.8
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTabWidget tab;
    QStringList lst;

    lst << "Linux" << "Windows" << "MacOSX" << "Andriod";
    foreach (QString str, lst) {
        tab.addTab(new QLabel(str, &tab), QPixmap(":/jpg/" + str + ".jpg"), str);
    }
    tab.resize(420, 100);
    tab.show();

    return app.exec();
}
