#include <QtWidgets>

#include "myclient.hpp"

MyClient::MyClient(const QString &strHost, int nPort, QWidget *parent)
    : QWidget(parent)
{
    m_pTcpSoket = new QTcpSocket(this);

    m_pTcpSoket->connectToHost(strHost, nPort);

    connect(m_pTcpSoket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSoket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSoket, SIGNAL(error(QAbstractSocket::SoketError)), SLOT(slotError(QAbstractSocket::SoketError)));

    m_ptxtInfo = new QTextEdit;
    m_ptxtInfo->setReadOnly(true);

    m_ptxtInput = new QLineEdit;

    QPushButton *pcmd = new QPushButton("&Send");

    connect(pcmd, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(m_ptxtInput, SIGNAL(returnPressed()), SLOT(slotSendToServer()));    //слот нужен для реакции на Enter

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
    pvbxLayout->addWidget(m_ptxtInfo);
    pvbxLayout->addWidget(m_ptxtInput);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);
}

MyClient::~MyClient()
{

}

void MyClient::slotReadyRead()
{
    QDataStream in(m_pTcpSoket);
    in.setVersion(QDataStream::Qt_5_3);

    while(true) {
        if(!m_nNextBlockSize) {
            if(m_pTcpSoket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if(m_pTcpSoket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }

        QTime time;
        QString str;
        in >>time >> str;

        m_ptxtInfo->append(time.toString() + " " + str);
        m_nNextBlockSize = 0;
    }
}

void MyClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError = "Error: ";

    if(err == QAbstractSocket::HostNotFoundError) {
        strError += "The host was not found.";
    }
    else if(err == QAbstractSocket::RemoteHostClosedError) {
        strError += "The remote host is closed.";
    }
    else if(err == QAbstractSocket::ConnectionRefusedError) {
        strError += "The connection was refused.";
    }

    m_ptxtInfo->append(strError);
}

void MyClient::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << QTime::currentTime() << m_ptxtInput->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    m_pTcpSoket->write(arrBlock);
    m_ptxtInfo->setText("");
}

void MyClient::slotConnected()
{
    m_ptxtInfo->append("Received the connected() signal");
}

























