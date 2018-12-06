#pragma once

#include "baserequest.hpp"

class RequestUpdateUserInfo : public QObject, public BaseRequest
{
    Q_OBJECT
public:
    explicit RequestUpdateUserInfo(QObject *parent = nullptr);
    Q_DISABLE_COPY(RequestUpdateUserInfo)

    Q_INVOKABLE bool checkFirstName(QString name);
    Q_INVOKABLE bool checkSurname(QString surname);
    Q_INVOKABLE bool checkNickname(QString nickname);
    Q_INVOKABLE void sendRequest() override;

    ~RequestUpdateUserInfo() override;

signals:
    void signalSendToServer(nlohmann::json);

public slots:
};

