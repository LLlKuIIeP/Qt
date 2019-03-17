#include <QDebug>

#include "someclass.h"
#include "server.h"


Server::Server(QObject *parent): MessagerSource(parent)
{
    m_some = QVariant::fromValue(SomeClass());
}

Server::~Server()
{
}

/*virtual*/void Server::slotServer()
{
    qDebug() << "Server::slotServer";
    emit signalServer(m_vec);
}

QVariant Server::some() const
{
    return m_some;
}

//void Server::someChanged()
//{

//}

void Server::setSome(QVariant other)
{
    m_some = other;
}
