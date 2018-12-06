#include "requestregister.hpp"

RequestRegister::RequestRegister(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)), Qt::DirectConnection);
}

void RequestRegister::sendRequest()
{
    nlohmann::json json;

    json["command"] = "request_code";
    ///json["payload"]["phone"] = "79263479454";
    //json["payload"]["phone"] = "79653215709";
    //json["payload"]["phone"] = "79778798456";
    json["payload"]["phone"] = UserInfo::Instance().getPhoneNumber().toStdString();
    //json["payload"]["type"] = "login";
    json["payload"]["type"] = "register";

    emit signalSendToServer(json);
}

void RequestRegister::setPhoneNumber(QString phone)
{
    UserInfo::Instance().setPhoneNumber(phone);
}

RequestRegister::~RequestRegister()
{
    disconnect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)));
}
