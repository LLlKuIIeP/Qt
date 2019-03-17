#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
}

Client::Client(QSharedPointer<MessagerReplica> s_ptr)
{
    m_sPtr = s_ptr;
    connect(m_sPtr.data(), &MessagerReplica::initialized, this, &Client::init);
}

void Client::sendToServer()
{
    m_sPtr.data()->slotServer();
}

void Client::slotReceivedServer(QVector<int> &vec)
{
    qDebug() << "Client::slotReceivedServer";
    Q_UNUSED(vec);
}

void Client::init()
{
    qDebug() << "Client::init";
    connect(m_sPtr.data(), &MessagerReplica::signalServer, this, &Client::slotReceivedServer);
    sendToServer();
}
