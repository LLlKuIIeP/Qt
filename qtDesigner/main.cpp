//Листинг 44.1
#include <QtWidgets>
#include "ui_MyForm.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *form = new QWidget;
    Ui::MyForm ui;
    ui.setupUi(form);

    form->show();

    return app.exec();
}
