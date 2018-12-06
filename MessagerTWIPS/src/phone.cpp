#include <tuple>
#include <QMap>
#include <QRegExp>

#include "phone.hpp"

const QMap<QString, std::tuple<QString, quint16>> map_codes_country = {
    { "Russia Federation", { "+7", 10 } },
    { "USA", { "+1", 10 } },
    { "China", { "+8", 10 } }
};

Phone::Phone(QObject *parent) : QObject(parent)
{}

bool Phone::checkAndSavePhone(QString country, QString phone)
{
    auto it = map_codes_country.find(country);

    if(!checkNubmer(phone, std::get<1>(it.value()))) {
        return false;
    }

    savePhoneNumber(phone);
    saveCountryCode(std::get<0>(it.value()));
    saveCountryName(country);
    return true;
}

bool Phone::countryNameChanged(QString country)
{
    auto it = map_codes_country.find(country);
    if(it == map_codes_country.end()) {
        return false;
    }

    m_country_code = std::get<0>(it.value());
    emit signalCountryCodeChanged();

qDebug() << "countryCodeChanged";

return true;
}

QString Phone::getCountryCode() const
{
    return m_country_code;
}

void Phone::setCountryCode(const QString &country_code)
{
    m_country_code = country_code;
}

const QString Phone::getFullPhoneNumber() const
{
    QString full_phone_number;
    full_phone_number += m_country_code + m_phone_number;
    full_phone_number = full_phone_number.replace("+", "");

    return full_phone_number;
}

bool Phone::checkNubmer(QString &phone, const quint16 &lenght)
{
    QRegExp rgx("[-)(\\s]");
    phone = phone.replace(rgx, "");

    if(phone.length() != lenght) {
        qWarning() << "Invalid length phone number";
        return false;
    }

    QRegExp rgxDigit("\\d*");
    if(!rgxDigit.exactMatch(phone)) {
        qWarning() << "Invalid phone number is not digits";
        return false;
    }

    return true;
}

void Phone::savePhoneNumber(QString &phone)
{
    m_phone_number = phone;
}

void Phone::saveCountryCode(const QString &country_code)
{
    m_country_code = country_code;
    emit signalCountryCodeChanged();
}

void Phone::saveCountryName(QString &country)
{
    m_country_name = country;
}
