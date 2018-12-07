//Листинг 39.14
#include <QApplication>
#include "udpserver.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpServer server;

    server.show();

    return a.exec();
}
