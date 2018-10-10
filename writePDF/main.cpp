//Листинг 10.4
#include <QtWidgets>
#include <QPrinter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextEdit *ptxt = new QTextEdit("This is a <b>TEST</b>");
    QPrinter printer(QPrinter::HighResolution); //высокое разрешение
    printer.setOutputFormat(QPrinter::PdfFormat);   //запись в pdf формате
    printer.setOutputFileName("output.pdf");
    ptxt->document()->print(&printer);
    //класс QPdfWriter - тоже можно использовать для создания pdf файлов

    return app.exec();
}
