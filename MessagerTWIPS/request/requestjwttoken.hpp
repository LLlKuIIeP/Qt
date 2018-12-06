#pragma once

#include "baserequest.hpp"

class RequestJwtToken : public QObject, public BaseRequest
{
    Q_OBJECT
    Q_PROPERTY(QString m_register_code READ getRegisterCode WRITE setRegisterCode)

public:
    explicit RequestJwtToken(QObject *parent = nullptr);
    Q_DISABLE_COPY(RequestJwtToken)

    Q_INVOKABLE void sendRequest() override;
    Q_INVOKABLE bool checkRegisterCode(QString register_code);

    void setRegisterCode(const QString &register_code);
    QString getRegisterCode() const;

    ~RequestJwtToken() override;

signals:
    void signalSendToServer(nlohmann::json);

public slots:

private:
    QString m_str_register_code;
};
