#pragma once

#include "baseresponse.hpp"

class ResponseUpdateUserInfo : public QObject, public BaseResponse
{
    Q_OBJECT
public:
    explicit ResponseUpdateUserInfo(QObject *parent = nullptr);
    Q_DISABLE_COPY(ResponseUpdateUserInfo)

    bool getResponse(const nlohmann::json &json) override;

signals:

public slots:
};

