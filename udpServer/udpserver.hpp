#pragma once

#include <QtWidgets>
#include <QUdpSocket>

class UdpServer : public QTextEdit
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = nullptr);
    ~UdpServer();

private:
    QUdpSocket *m_pudp;

private slots:
    void slotSendDatagram();
};

