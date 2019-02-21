#include "localclient.h"

LocalClient::LocalClient(QWidget *parent): QWidget(parent)
{
    m_plocalSocket = new QLocalSocket(this);

    connect(m_plocalSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(m_plocalSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(m_plocalSocket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(slotError(QLocalSocket::LocalSocketError)));

    sendMessageToServer();
}

LocalClient::~LocalClient()
{
    m_plocalSocket->close();
}

void LocalClient::slotConnected()
{
    qDebug() << "LocalClient::slotConnected";
}

void LocalClient::slotReadyRead()
{
    QDataStream in(m_plocalSocket);
    in.setVersion(QDataStream::Qt_5_10);    //нужен для протокола данных, чтобы данные воспринимались однозначно без искажений

    if(m_plocalSocket->bytesAvailable() == 0) {
        //прилетел блок нулевой длины, т.е. данных нет
        return;
    }

    QString str;
    in >> str;

    qDebug() << "Input message:" << str;
    m_plocalSocket->disconnectFromServer();
}

void LocalClient::slotError(QLocalSocket::LocalSocketError err)
{
    QString error = "Error";
    if(err == QLocalSocket::ServerNotFoundError) {
        error += "The local socket name was not found.";
    }
    else if(err == QLocalSocket::SocketTimeoutError) {

    }
    //и т.д. но потом

    qDebug() << error;
}

void LocalClient::sendMessageToServer()
{
    m_plocalSocket->abort();
    m_plocalSocket->connectToServer("my_local_server");

    QByteArray arrByte;
    QDataStream out(&arrByte, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << "Hello world!";

    m_plocalSocket->write(arrByte);
    m_plocalSocket->flush();
    //m_plocalSocket->disconnectFromServer();
}
