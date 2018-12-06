#include <iostream>

#include "responsetoken.hpp"

ResponseToken::ResponseToken(QObject *parent) : QObject(parent)
{}

bool ResponseToken::getResponse(const nlohmann::json &json)
{
    qDebug() << "ResponseToken::getResponse";
    std::string s = json.dump(4);
    std::cout << s << std::endl;

    //auto it_token = findKey(json, "token");
    if(auto it_token(findKey(json, "token")); it_token.key() == "token") {
        UserInfo::Instance().setToken(it_token.value());
    }
    else {
        qWarning() << "Bad response, not find element:" << it_token.key().front();
        return false;
    }

    return true;
}
