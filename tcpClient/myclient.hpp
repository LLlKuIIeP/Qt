#pragma once

#include <QWidget>
#include <QTcpSocket>

class QTextEdit;
class QLineEdit;


class MyClient : public QWidget
{
    Q_OBJECT

public:
    MyClient(const QString &strHost, int nPOrt, QWidget *parent = nullptr);
    ~MyClient();

private:
    QTcpSocket *m_pTcpSoket;
    QTextEdit *m_ptxtInfo;
    QLineEdit *m_ptxtInput;
    quint16 m_nNextBlockSize;

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};


