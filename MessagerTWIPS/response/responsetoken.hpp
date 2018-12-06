#pragma once

#include "baseresponse.hpp"

class ResponseToken : public QObject, public BaseResponse
{
    Q_OBJECT
public:
    explicit ResponseToken(QObject *parent = nullptr);
    Q_DISABLE_COPY(ResponseToken)

    bool getResponse(const nlohmann::json &json) override;

signals:

public slots:
};
