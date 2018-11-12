//Листинг 27.11
#include <QApplication>
#include "videoplayer.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    VideoPlayer videoPlayer;

    videoPlayer.resize(400, 450);
    videoPlayer.show();

    return app.exec();
}
