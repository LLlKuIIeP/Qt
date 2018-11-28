#include <QtWidgets>

#include <QTcpServer>
#include <QTcpSocket>

#include "myserver.hpp"

MyServer::MyServer(int nPort, QWidget *parent) : QWidget(parent), m_nNextBlockSize(0)
{
    m_ptcpServer = new QTcpServer(this);
    if(!m_ptcpServer->listen(QHostAddress::Any, static_cast<quint16>(nPort))) { //для запуска сервера вызываем listen
        QMessageBox::critical(nullptr, "Server Error", "Unable to start the server:" + m_ptcpServer->errorString());
        m_ptcpServer->close();
        return;
    }

    connect(m_ptcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));    //при каждом новом соединении отправляется сигнал

    m_ptxt = new QTextEdit;
    m_ptxt->setReadOnly(true);

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Server</H1>"));
    pvbxLayout->addWidget(m_ptxt);
    setLayout(pvbxLayout);
}

void MyServer::slotNewConnection()
{
    QTcpSocket *pClientSocket = m_ptcpServer->nextPendingConnection();  //nextPendingConnection - возвращает сокет для связи с клиентом
    connect(pClientSocket, SIGNAL(disconnected()), pClientSocket, SLOT(deleteLater())); //deleteLater - нужен для уничтожения сокета при разрыве соединения
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(pClientSocket, "Server Response: Connected!");
}

void MyServer::slotReadClient()
{
    QTcpSocket *pClientSocket = qobject_cast<QTcpSocket*>(sender());
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_3);

    while(true) {
        if(!m_nNextBlockSize) {                                         //если 0, то блок неизвестной длины
            if(pClientSocket->bytesAvailable() < sizeof(quint16)) {     //если длина блока меньше 2 байт, ничего не считываем
                break;
            }
            in >> m_nNextBlockSize;
        }

        if(pClientSocket->bytesAvailable() < m_nNextBlockSize) {        //считанных данных нет
            break;
        }

        //считываем данные
        QTime time;
        QString str;
        in >> time >> str;

        QString strMessage = time.toString() + " Client has sent - " + str;
        m_ptxt->append(strMessage);

        m_nNextBlockSize = 0;

        sendToClient(pClientSocket, "Server Responce: Received \"" + str + "\"");
    }
}

void MyServer::sendToClient(QTcpSocket *pSocket, const QString &str)
{
    QByteArray arrBlock;

    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out << static_cast<quint16>(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << static_cast<quint16>(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);
}



