//Листинг 7.4
#include <QApplication>
#include "progress.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Progress progress;
    progress.show();

    return app.exec();
}
