#include "localserver.h"

LocalServer::LocalServer(QWidget *parent): QWidget(parent)
{
    //QMessageBox::warning(this, "warning", "blablabla", QMessageBox::Yes);
    m_plocalServer = new QLocalServer(this);

    m_plocalServer->removeServer("my_local_server");

    QString serverName = "my_local_server";

    if(!m_plocalServer->listen(serverName)) {
        QMessageBox::warning(this,
                              tr("Warning"),
                              tr("Обмен данными с модулем \"%1\" по локальному соединению невозможен.\n\n"
                                 "Unable to start the local server: %2")
                             .arg("blablabla")
                             .arg(m_plocalServer->errorString()));
        m_plocalServer->close();
    }
    else {
        connect(m_plocalServer, &QLocalServer::newConnection, this, &LocalServer::slotNewConnection);
    }
}

LocalServer::~LocalServer()
{
    m_plocalServer->close();
    m_plocalServer->removeServer("my_local_server");
}

void LocalServer::slotNewConnection()
{
    qDebug() << "LocalServer::slotNewConnection";

    QLocalSocket *clientSocket;
    clientSocket = m_plocalServer->nextPendingConnection();  //получили сокет нового соединения

    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));    //сигнал readyRead высылается при новом сообщении от клиента
    connect(clientSocket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(slotError(QLocalSocket::LocalSocketError))); //для обработки ошибок сброса соединения
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));   //deleteLater нужен для уничтожения сокета при разрыве соединения
}

void LocalServer::slotReadyRead()
{
    QLocalSocket *clientSocket;
    clientSocket = qobject_cast<QLocalSocket*>( sender() );

    if(clientSocket == nullptr) {
        //TODO
        return;
    }

    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_10);    //нужен для протокола данных, чтобы данные воспринимались однозначно без искажений

    if(clientSocket->bytesAvailable() == 0) {
        //прилетел блок нулевой длины, т.е. данных нет
        return;
    }

    qint64 len = clientSocket->bytesAvailable();
    char *c;
    QString str;
    for(qint64 i = 0; i < len; ++i){
        in >> c;
        str.append(c);
    }


    qDebug() << "Input message:" << str;
    //clientSocket->disconnectFromServer();
}

void LocalServer::slotError(QLocalSocket::LocalSocketError err)
{
    QString error = "Error";
    if(err == QLocalSocket::SocketAccessError) {
        error += "The socket operation failed because the application lacked the required privileges.";
    }
    else if(err == QLocalSocket::SocketTimeoutError) {

    }
    //и т.д. но потом

    qDebug() << error;
}











