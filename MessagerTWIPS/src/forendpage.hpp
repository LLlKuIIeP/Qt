#pragma once

#include <QObject>

class ForEndPage : public QObject
{
    Q_OBJECT
public:
    explicit ForEndPage(QObject *parent = nullptr);

    Q_INVOKABLE QString getFirstName();
    Q_INVOKABLE QString getSurname();
    Q_INVOKABLE QString getNickname();
    Q_INVOKABLE QString getPhoneNumber();
    Q_INVOKABLE QString getUserId();
    Q_INVOKABLE QString setUserCountry();
    Q_INVOKABLE QString getJwtToken();

signals:

public slots:
};
