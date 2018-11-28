#pragma once

#include <QWidget>

class QTcpServer;
class QTextEdit;
class QTcpSocket;

class MyServer : public QWidget
{
    Q_OBJECT

public:
    MyServer(int, QWidget *parent = nullptr);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();          //принимает данные от клиента

private:
    QTcpServer *m_ptcpServer;       //основа управления сервером
    QTextEdit *m_ptxt;              //для информирования о происходящих соединениях
    quint16 m_nNextBlockSize;       //хранит длину полученного от сокета блока

    void sendToClient(QTcpSocket*, const QString&); //отправляет данные клиенту
};
