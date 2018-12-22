//Листинг 49.5
#include <QtWidgets>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *plbl = new QLabel;

    QJSEngine scriptEngine;
    QJSValue scriptLbl = scriptEngine.newQObject(plbl);
    scriptEngine.globalObject().setProperty("lbl", scriptLbl);
    scriptEngine.evaluate("lbl.text = 'Hello, JavaScript!'");
    scriptEngine.evaluate("lbl.show()");

    return app.exec();
}
