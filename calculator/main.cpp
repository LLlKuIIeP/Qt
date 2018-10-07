//Листинг 6.6
#include <QtWidgets>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calculator;

    calculator.setWindowTitle("Calculator");
    calculator.resize(230, 200);
    calculator.show();

    return app.exec();
}
