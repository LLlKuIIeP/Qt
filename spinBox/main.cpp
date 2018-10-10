//Листинг 10.10
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSpinBox spb;

    spb.setRange(1, 100);
    spb.setSuffix(" MB");
    spb.setButtonSymbols(QSpinBox::PlusMinus);
    spb.setWrapping(true);	//устанавливает зацикливание после 100 идет 1
    spb.resize(100, 30);
    spb.show();

    QApplication::setStyle("Windows");

    return app.exec();
}
