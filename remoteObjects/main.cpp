#include <QApplication>
#include <QRemoteObjectHost>
#include <QUrl>

#include "server.h"
#include "client.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///для кастомного класса обязательно
    qRegisterMetaTypeStreamOperators<SomeClass>("SomeClass");

    ///Сервер
    Server remServer;
    //QRemoteObjectHost remHost(QUrl(QStringLiteral("local:my_server")));
    QRemoteObjectHost remHost(QUrl("tcp://0.0.0.0:9999"));
    remHost.enableRemoting(&remServer);
    ///----------------------


    ///Клиент
    QRemoteObjectNode remNode;
    //remNode.connectToNode(QUrl(QStringLiteral("local:my_server")));
    remNode.connectToNode(QUrl("tcp://localhost:9999"));

    QSharedPointer<MessagerReplica> sPtr;
    sPtr.reset(remNode.acquire<MessagerReplica>());

    Client client(sPtr);
    ///----------------------

    return a.exec();
}
