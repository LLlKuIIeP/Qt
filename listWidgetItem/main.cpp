//Листинг 11.1
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList lst;
    QListWidget lwg;
    QListWidgetItem *piten = nullptr;

    lwg.setIconSize(QSize(48, 48));
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach (QString str, lst) {
        piten = new QListWidgetItem(str, &lwg);
        piten->setIcon(QPixmap(":/jpg/" + str + ".jpg"));
    }

    lwg.resize(150, 125);
    lwg.show();

    return app.exec();
}
