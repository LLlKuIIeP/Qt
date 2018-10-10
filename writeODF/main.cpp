//Листинг 10.3
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextEdit *ptxt = new QTextEdit("This is a <b>TEST</b>");
    QTextDocumentWriter writer;
    writer.setFormat("odf");
    writer.setFileName("output.odf");
    writer.write(ptxt->document());

    return app.exec();
}
