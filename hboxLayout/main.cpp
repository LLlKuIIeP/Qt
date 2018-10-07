//Листинг 6.3
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");

    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->setContentsMargins(10, 10, 10, 10); // задает толщину рамки с 4ех сторон
    phbxLayout->setSpacing(20); //расстояние между кнопками
    phbxLayout->addWidget(pcmdA);
    phbxLayout->addWidget(pcmdB);
    phbxLayout->addWidget(pcmdC);
    wgt.setLayout(phbxLayout);   //всем присвоится предок wgt, поэтому утечки памяти не будет

    wgt.show();

    return app.exec();
}
