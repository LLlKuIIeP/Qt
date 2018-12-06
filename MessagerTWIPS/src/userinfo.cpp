#include <iostream>

#include "userinfo.hpp"
#include "connector/connectorsqlite.hpp"

UserInfo::UserInfo(QObject *parent) : QObject(parent)
{}

UserInfo& UserInfo::Instance(QObject *parent)
{
    static UserInfo *connector = nullptr;
    if(connector == nullptr) {
        connector = new UserInfo(parent);
    }

    return *connector;
}

bool UserInfo::writeUserInfoInDB()
{
    return ConnectorSQLite::Instance().upsertUserInfo(
                UserInfo::Instance().getUserId(),
                UserInfo::Instance().getJwtToken().data(),
                UserInfo::Instance().getFirstName(),
                UserInfo::Instance().getPhoneNumber(),
                UserInfo::Instance().getSurname(),
                UserInfo::Instance().getNickname(),
                UserInfo::Instance().getUserCountry()
                );
}

void UserInfo::setPhoneNumber(const QString &phone)
{
    m_str_phone_number = phone;
    qDebug() << "ClientInfo::setPhoneNumber" << m_str_phone_number;
}

const QString UserInfo::getPhoneNumber() const
{
    return m_str_phone_number;
}

void UserInfo::setToken(const std::string &token)
{
    m_str_token = token;
    std::cout << "ClientInfo::setToken: " << m_str_token << std::endl;
}

const std::string UserInfo::getToken() const
{
    return m_str_token;
}

void UserInfo::setJwtToken(const std::string &jwt_token)
{
    m_str_jwt_token = jwt_token;
}

const std::string UserInfo::getJwtToken() const
{
    return m_str_jwt_token;
}

void UserInfo::setUserId(int user_id)
{
    m_str_user_id = user_id;
}

int UserInfo::getUserId()
{
    return m_str_user_id;
}

void UserInfo::setUserCountry(const QString &country)
{
    m_str_country = country;
}

const QString UserInfo::getUserCountry()
{
    return m_str_country;
}

void UserInfo::setFirstName(const QString &first_name)
{
    m_str_first_name = first_name;
}

const QString UserInfo::getFirstName()
{
    return m_str_first_name;
}

void UserInfo::setSurname(const QString &surname)
{
    m_str_surname = surname;
}

const QString UserInfo::getSurname()
{
    return m_str_surname;
}

void UserInfo::setNickname(const QString &nickname)
{
    m_str_nickname = nickname;
}

const QString UserInfo::getNickname()
{
    return m_str_nickname;
}


