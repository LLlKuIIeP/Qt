#pragma once

#include <QWidget>
#include <QLocalSocket>


class LocalClient : public QWidget
{
    Q_OBJECT

public:
    LocalClient(QWidget *parent = nullptr);
    ~LocalClient();

private slots:
    void slotConnected();
    void slotReadyRead();
    void slotError(QLocalSocket::LocalSocketError err);

private:
    QLocalSocket *m_plocalSocket;

    void sendMessageToServer();
};

