#include <iostream>

#include "responsejwttoken.hpp"

ResponseJwtToken::ResponseJwtToken(QObject *parent) : QObject(parent)
{}

bool ResponseJwtToken::getResponse(const nlohmann::json &json)
{
    qDebug() << "ResponseJwtToken::getResponse";
    std::string s = json.dump(4);
    std::cout << s << std::endl;

    if(auto it_jwt_token(findKey(json, "jwt")); it_jwt_token.key() == "jwt") {
        UserInfo::Instance().setJwtToken(it_jwt_token.value());
    }
    else {
        qWarning() << "Bad response, not find element:" << it_jwt_token.key().front();
        return false;
    }

    if(auto it_user_id(findKey(json, "user_id")); it_user_id.key() == "user_id") {
        (void)UserInfo::Instance().setUserId(it_user_id.value());
    }
    else {
        qWarning() << "Bad response, not find element:" << it_user_id.key().front();
        return false;
    }

    return true;
}
