//Листинг 6.4
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");
    QPushButton *pcmdD = new QPushButton("D");

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->setContentsMargins(5, 5, 5, 5); // задает толщину рамки с 4ех сторон
    phbxLayout->setSpacing(15); //расстояние между кнопками
    phbxLayout->addWidget(pcmdC);
    phbxLayout->addWidget(pcmdD);

    pvbxLayout->setContentsMargins(5, 5, 5, 5); // задает толщину рамки с 4ех сторон
    pvbxLayout->setSpacing(15); //расстояние между кнопками
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addLayout(phbxLayout);  //добавить в вертикальную компоновку горизонтальную
    wgt.setLayout(pvbxLayout);   //всем присвоится предок wgt, поэтому утечки памяти не будет

    wgt.show();

    return app.exec();
}
