#pragma once

#include <QObject>
#include <QDebug>

#include <nlohmann/json.hpp>

#include "src/phone.hpp"
#include "src/userinfo.hpp"

class BaseResponse
{
public:

    virtual bool getResponse(const nlohmann::json &json);
    nlohmann::json::const_iterator findKey(const nlohmann::json &json, const std::string key);

    virtual ~BaseResponse() {}
};

