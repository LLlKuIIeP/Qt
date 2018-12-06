#include <string>
#include <array>

#include "country.hpp"
#include "userinfo.hpp"

#define ELEMETS 7

const std::array<std::string, ELEMETS> arr_coutry {
    "Russain Federation", "Ukraine", "Belarus", "Kazakhstan", "Poland", "Moldova", "Uzbekistan"
};

Country::Country(QObject *parent) : QObject(parent)
{
    for(auto &elem : arr_coutry) {
       m_arr.append(elem.c_str());
    }
}

void Country::countryNameChanged(QString country)
{
    m_str_country_selected = country;
}

void Country::saveCountry(QString country)
{
    UserInfo::Instance().setUserCountry(country);
}

bool Country::saveUserInfo()
{
    //FAKE
    return true;
    return UserInfo::Instance().writeUserInfoInDB();
}

QStringList Country::getArr()
{
    return m_arr;
}
