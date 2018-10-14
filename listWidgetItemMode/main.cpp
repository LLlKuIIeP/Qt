//Листинг 11.2
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList lst;
    QListWidget lwg;
    QListWidgetItem *piten = nullptr;

    lwg.setIconSize(QSize(48, 48));
    lwg.setSelectionMode(QAbstractItemView::MultiSelection);   //установка режима выбора нескольких элементов
    lwg.setViewMode(QListView::IconMode);   //режим пиктограмм
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach (QString str, lst) {
        piten = new QListWidgetItem(str, &lwg);
        piten->setIcon(QPixmap(":/jpg/" + str + ".jpg"));
        piten->setFlags(Qt::ItemIsEnabled           //разрешить доступным
                        | Qt::ItemIsSelectable      //выделяемым
                        | Qt::ItemIsEditable        //редактируемым
                        | Qt::ItemIsDragEnabled);   //перетаскиваемым
    }

    lwg.resize(150, 125);
    lwg.show();

    return app.exec();
}
