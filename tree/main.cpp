//Листинг 11.4
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTreeWidget twg;
    QStringList lst;

    lst << "Folders" << "User Space";
    twg.setHeaderLabels(lst);       //задает заголовки столбцов
    twg.setSortingEnabled(true);    //сортировка по возрастанию

    QTreeWidgetItem *ptwgItem = new QTreeWidgetItem(&twg);  //twg - предок для всех создаваемых элементов
    ptwgItem->setText(0, "Local Dosk(C)");
    ptwgItem->setIcon(0, QPixmap(":/png/drive.png"));

    QTreeWidgetItem *ptwgItemDir = nullptr;
    for (int i = 1; i < 20; ++i) {
        ptwgItemDir = new QTreeWidgetItem(ptwgItem);
        ptwgItemDir->setText(0, "Directory" + QString::number(i));
        ptwgItemDir->setText(1, QString::number(i) + "MB");
        ptwgItemDir->setIcon(0, QPixmap(":/png/folder.png"));
    }
    ptwgItem->setExpanded(true);    //разрешить сортировку
    twg.resize(350, 310);
    twg.show();

    return app.exec();
}
