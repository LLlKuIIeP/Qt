//Листинг 39.17
#include <QApplication>
#include "udpclient.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UdpClient client;

    client.show();

    return a.exec();
}
