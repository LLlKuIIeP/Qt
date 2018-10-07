//Листинг 6.5
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");
    QPushButton *pcmdD = new QPushButton("D");

    QGridLayout *pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5); // задает толщину рамки с 4ех сторон
    pgrdLayout->setSpacing(15); //расстояние между кнопками
    pgrdLayout->addWidget(pcmdA, 0, 0); //второй параметр - строка, третий - столбец
    pgrdLayout->addWidget(pcmdB, 0, 1);
    pgrdLayout->addWidget(pcmdC, 1, 0);
    pgrdLayout->addWidget(pcmdD, 1, 1);

    wgt.setLayout(pgrdLayout);   //всем присвоится предок wgt, поэтому утечки памяти не будет

    wgt.show();

    return app.exec();
}
