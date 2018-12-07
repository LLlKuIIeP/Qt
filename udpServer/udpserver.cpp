#include <QUdpSocket>
#include <QTimer>

#include "udpserver.hpp"

UdpServer::UdpServer(QWidget *parent)
    : QTextEdit(parent)
{
    setWindowTitle("UdpServer");

    m_pudp = new QUdpSocket(this);

    QTimer *ptimer = new QTimer(this);
    ptimer->setInterval(500);
    ptimer->start();
    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendDatagram()));
}

UdpServer::~UdpServer()
{

}

void UdpServer::slotSendDatagram()
{
    QByteArray baDatagram;
    QDataStream out(&baDatagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);

    QDateTime dt = QDateTime::currentDateTime();
    append("Sent:" + dt.toString());

    out << dt;

    m_pudp->writeDatagram(baDatagram, QHostAddress::LocalHost, 2424);
}
