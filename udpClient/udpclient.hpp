#pragma once

#include <QtWidgets>
#include <QUdpSocket>

class UdpClient : public QTextEdit
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = nullptr);
    ~UdpClient();

private:
    QUdpSocket *m_pudp;

private slots:
    void slotProcessDatagrams();
};

