#include <QRegExp>

#include <nlohmann/json.hpp>

#include "requestupdateuserinfo.hpp"
#include "connector/connectorsqlite.hpp"

RequestUpdateUserInfo::RequestUpdateUserInfo(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)), Qt::DirectConnection);
}

bool RequestUpdateUserInfo::checkFirstName(QString name)
{
    if(name.length() < 5 || name.length() > 35) {
        qWarning() << "Invalid length name";
        return false;
    }

    QRegExp rgxDigit("\\w*");
    if(!rgxDigit.exactMatch(name)) {
        qWarning() << "Invalid name, need use charaster only";
        return false;
    }

    UserInfo::Instance().setFirstName(name);

    return true;
}

bool RequestUpdateUserInfo::checkSurname(QString surname)
{
    if(surname.length() > 35) {
        qWarning() << "Invalid length surname";
        return false;
    }

    UserInfo::Instance().setSurname(surname);

    return true;
}

bool RequestUpdateUserInfo::checkNickname(QString nickname)
{
    if(nickname.length() > 35) {
        qWarning() << "Invalid length nickname";
        return false;
    }

    if(nickname.length() > 1) {
        UserInfo::Instance().setNickname(nickname.replace("@", ""));
    }

    return true;
}

void RequestUpdateUserInfo::sendRequest()
{
    if(UserInfo::Instance().getNickname() == "") {
        UserInfo::Instance().setNickname(UserInfo::Instance().getFirstName());
    }

    nlohmann::json json;

    json["command"] = "profile_update";
    json["jwt"] = UserInfo::Instance().getJwtToken();
    json["payload"]["name"] = UserInfo::Instance().getNickname().toStdString();
    json["payload"]["first_name"] = UserInfo::Instance().getFirstName().toStdString();
    json["payload"]["surname"] = UserInfo::Instance().getSurname().toStdString();
    json["payload"]["phone"] = UserInfo::Instance().getPhoneNumber().toStdString();

    emit signalSendToServer(json);
}

RequestUpdateUserInfo::~RequestUpdateUserInfo()
{
    disconnect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)));
}
