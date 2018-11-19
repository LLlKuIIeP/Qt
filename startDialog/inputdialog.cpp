#include <QtWidgets>
#include "inputdialog.hpp"
#include <QtDebug>
InputDialog::InputDialog(QWidget *parent) : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint) // флаги доп инфо на окне
{
    qDebug() << "InputDialog";
    m_ptxtFirstName = new QLineEdit;
    m_ptxtLastName = new QLineEdit;

    QLabel *plblFirstName = new QLabel("&First Name");
    QLabel *plblLastName = new QLabel("&Last Name");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton *pcmdOk = new QPushButton("&Ok");
    QPushButton *pcmdCancle = new QPushButton("&Cancle");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancle, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout *ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2, 0);
    ptopLayout->addWidget(pcmdCancle, 2, 1);
    setLayout(ptopLayout);
}

QString InputDialog::firstName() const
{
    return m_ptxtFirstName->text();
}

QString InputDialog::lastName() const
{
    return m_ptxtLastName->text();
}
