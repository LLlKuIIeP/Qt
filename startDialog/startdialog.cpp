#include "startdialog.hpp"
#include <QtDebug>
StartDialog::StartDialog(QWidget *parent): QPushButton("Press Me", parent)
{
    connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
}

void StartDialog::slotButtonClicked()
{
    qDebug() << "slotButtonCliceked";
    InputDialog *pInputDialog = new InputDialog;

    if(pInputDialog->exec() == QDialog::Accepted) { //запуск модального диалогового окна, т.к. окна по вверх всех окон и которое нельзя пройти мимо
                                                    //осуществляется с помощью .exec() данный подход
        QMessageBox::information(nullptr, "Information", "First Name: " + pInputDialog->firstName() + "\nLast Name: " + pInputDialog->lastName());
    }

    delete pInputDialog;
}
