//Листинг 10.11
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDateTimeEdit dateTimeEdit(QDateTime::currentDateTime());   //currentDateTime статическая ф-я возв-ая текущую дату и время
    dateTimeEdit.show();

    return app.exec();
}
