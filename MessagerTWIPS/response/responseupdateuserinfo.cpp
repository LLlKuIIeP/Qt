#include <iostream>

#include "responseupdateuserinfo.hpp"

ResponseUpdateUserInfo::ResponseUpdateUserInfo(QObject *parent) : QObject(parent)
{}

bool ResponseUpdateUserInfo::getResponse(const nlohmann::json &json)
{
    qDebug() << "ResponseUpdateUserInfo::getResponse";
    std::string s = json.dump(4);
    std::cout << s << std::endl;

    return true;
}
