#pragma once

#include "baserequest.hpp"

class Phone;

class RequestRegister : public QObject, public BaseRequest
{
    Q_OBJECT
public:
    explicit RequestRegister(QObject *parent = nullptr);
    Q_DISABLE_COPY(RequestRegister)

    Q_INVOKABLE void sendRequest() override;
    Q_INVOKABLE void setPhoneNumber(QString phone);

    ~RequestRegister() override;

signals:
    void signalSendToServer(nlohmann::json);


public slots:

private:
};
