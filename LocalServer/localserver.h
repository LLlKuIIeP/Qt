#pragma once

#include <QtWidgets>
#include <QLocalServer>
#include <QLocalSocket>


class LocalServer : public QWidget
{
    Q_OBJECT

public:
    LocalServer(QWidget *parent = nullptr);
    ~LocalServer();

private slots:
    void slotNewConnection();
    void slotReadyRead();
    void slotError(QLocalSocket::LocalSocketError err);

private:
    QLocalServer *m_plocalServer;
};

