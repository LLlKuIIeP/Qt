#pragma once

#include <QObject>
#include <QString>

#include "src/phone.hpp"
#include "src/userinfo.hpp"
#include "connector/connector.hpp"

class BaseRequest
{
public:
    virtual void sendRequest() = 0;

    virtual ~BaseRequest() {}
};
