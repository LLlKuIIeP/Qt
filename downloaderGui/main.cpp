//Листинг 39.20
#include <QApplication>
#include "downloadergui.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DownloaderGui downloaderGui;

    downloaderGui.show();
    downloaderGui.resize(280, 100);

    return app.exec();
}
