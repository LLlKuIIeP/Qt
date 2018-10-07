//Листинг 6.1
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");

    QBoxLayout *pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight); //LeftToRight - размещение слева на право
    pbxLayout->addWidget(pcmdA, 1); //добавляет виджет в компановку pcmdA, 1 - параметр растяжения кнопки
    pbxLayout->addWidget(pcmdB, 2);
    pbxLayout->addWidget(pcmdC, 3);
    wgt.setLayout(pbxLayout);   //всем присвоится предок wgt, поэтому утечки памяти не будет

    wgt.resize(450, 40);
    wgt.show();

    return app.exec();
}
