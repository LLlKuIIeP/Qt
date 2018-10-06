//Листинг 5.3
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QScrollArea sa; //виджет видовой прокрутки

    QWidget *pwgt = new QWidget;    //обычный виджет
    QPixmap pix(":/img/img.jpg");   //растровое изображение

    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
    pwgt->setPalette(pal);  //устанавливаем задний фон
    pwgt->setAutoFillBackground(true);  //автоматическое заполнение заднего фона
    pwgt->setFixedSize(pix.width(), pix.height());  //размеры виждета pwgt приводятся в соответсвие с размерами изображения

    sa.setWidget(pwgt); //добавляет в свое окно созданный виджет pwgt
    sa.resize(350, 150);
    sa.show();

    return app.exec();
}
