//Листинг 8.1
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;
    QPushButton *pcmdNormal = new QPushButton("&Normal Button");    //обычная кнопка

    QPushButton *pcmdToggle = new QPushButton("&Toggle Button");    //кнопка с двумя состояниями нажата/не нажата
    pcmdToggle->setCheckable(true); //устанавливает режим выключателя
    pcmdToggle->setChecked(true);   //переводит во включенное состояние

    QPushButton *pcmdFlat = new QPushButton("&Flat Button");
    pcmdFlat->setFlat(true);    //плоский вид, без рамки

    QPixmap pix(":/image/button.jpg");
    QPushButton *pcmdPix = new QPushButton("&Pixmap Button");
    pcmdPix->setIcon(pix);
    pcmdPix->setIconSize(QSize(30, 30));

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdNormal);
    pvbxLayout->addWidget(pcmdToggle);
    pvbxLayout->addWidget(pcmdFlat);
    pvbxLayout->addWidget(pcmdPix);

    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
