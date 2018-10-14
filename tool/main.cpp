//Листинг 11.9
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QToolBox tbx;
    QStringList lst;

    lst << "Linux" << "Windows" << "MacOSX" << "Andriod";
    foreach (QString str, lst) {
        tbx.addItem(new QLabel(str, &tbx), //указатель на виджет, который отображается
                    QPixmap(":/jpg/" + str + ".jpg"), //растровое изображение
                    str);   //текст вкладки
    }
    tbx.resize(100, 80);
    tbx.show();

    return app.exec();
}
