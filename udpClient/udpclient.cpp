#include <QUdpSocket>
#include <QTimer>

#include "udpclient.hpp"

UdpClient::UdpClient(QWidget *parent)
    : QTextEdit(parent)
{
    setWindowTitle("UdpClient");

    m_pudp = new QUdpSocket(this);
    m_pudp->bind(2424);
    connect(m_pudp, SIGNAL(readyRead()), SLOT(slotProcessDatagrams()));
}

UdpClient::~UdpClient()
{

}

void UdpClient::slotProcessDatagrams()
{
    QByteArray baDatagram;

    //принимаем все дейтаграммы, но важная только последняя, поэтому do ... while
    do {
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(), baDatagram.size());
    }
    while (m_pudp->hasPendingDatagrams());

    QDateTime dateTime;
    QDataStream in(&baDatagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_3);

    in >> dateTime;
    append("Received:" + dateTime.toString());
}
