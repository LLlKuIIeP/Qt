//Листинг 6.2
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");

    QBoxLayout *pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight); //LeftToRight - размещение слева на право
    pbxLayout->addWidget(pcmdA); //добавляет виджет в компановку pcmdA, 1 - параметр растяжения кнопки
    pbxLayout->addStretch(1);   //растяжение между кнопками
    pbxLayout->addWidget(pcmdB);
    wgt.setLayout(pbxLayout);   //всем присвоится предок wgt, поэтому утечки памяти не будет

    wgt.resize(350, 40);
    wgt.show();

    return app.exec();
}
