#pragma once

#include <QObject>

#include "rep_messager_source.h"


class Server : public MessagerSource
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server() override;

public slots:
    void slotServer() override;
    QVariant some() const;
    void setSome(QVariant other);

    //void someChanged();

private:
    QVector<int> m_vec;
    QVariant m_some;

};
