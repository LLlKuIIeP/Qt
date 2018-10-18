//Листинг 13.1
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSpinBox spb;

    QPalette pal = spb.palette();    //возвращает объект палитры
    pal.setBrush(QPalette::Button, QBrush(Qt::red, Qt::Dense3Pattern));
    pal.setColor(QPalette::ButtonText, Qt::blue);
    pal.setColor(QPalette::Text, Qt::magenta);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::green);  //устанавливает палитру только для активного окна QPalette::Active в поле Base

    spb.setPalette(pal);
    spb.resize(150, 74);
    spb.show();

    app.setStyle("Windows");    //стиль всегда будет одинаков
    //AQpplication::setPalette(pal);    //статический метод установит цветовую палитру для всего приложения
    return app.exec();
}
