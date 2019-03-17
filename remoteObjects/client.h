#pragma once

#include <QObject>
#include <QSharedPointer>

#include "someclass.h"

#include "rep_messager_replica.h"


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    explicit Client(QSharedPointer<MessagerReplica> s_ptr);

    void sendToServer();

private slots:
    void slotReceivedServer(QVector<int> &vec);
    void init();

private:
   QSharedPointer<MessagerReplica> m_sPtr;
};
