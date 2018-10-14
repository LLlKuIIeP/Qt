//Листинг 11.7
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QComboBox cbo;
    QStringList lst;

    lst << "John" << "Paul" << "Georg" << "Ringo";
    cbo.addItems(lst);
    cbo.setEditable(true);  //редактировать/добавлять элементы
    cbo.show();


    return app.exec();
}
