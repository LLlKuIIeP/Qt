#pragma once

#include "baseresponse.hpp"

class ResponseJwtToken : public QObject, public BaseResponse
{
    Q_OBJECT
public:
    explicit ResponseJwtToken(QObject *parent = nullptr);
    Q_DISABLE_COPY(ResponseJwtToken)

    bool getResponse(const nlohmann::json &json) override;

signals:

public slots:
};
