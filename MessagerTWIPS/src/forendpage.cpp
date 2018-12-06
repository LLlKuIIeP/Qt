#include <string>
#include "src/userinfo.hpp"
#include "forendpage.hpp"

ForEndPage::ForEndPage(QObject *parent) : QObject(parent)
{

}

QString ForEndPage::getFirstName()
{
    return UserInfo::Instance().getFirstName();
}

QString ForEndPage::getSurname()
{
    return UserInfo::Instance().getSurname();
}

QString ForEndPage::getNickname()
{
    return UserInfo::Instance().getNickname();
}

QString ForEndPage::getPhoneNumber()
{
    return UserInfo::Instance().getPhoneNumber();
}

QString ForEndPage::getUserId()
{
    return QString::number(UserInfo::Instance().getUserId());
}

QString ForEndPage::setUserCountry()
{
    return UserInfo::Instance().getUserCountry();
}

QString ForEndPage::getJwtToken()
{
    std::string str = UserInfo::Instance().getJwtToken();
    return QString(str.data());
}

