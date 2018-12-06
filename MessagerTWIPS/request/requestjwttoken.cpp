#include "requestjwttoken.hpp"

#define LEN_REGISTER_CODE 4

RequestJwtToken::RequestJwtToken(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)), Qt::DirectConnection);
}

void RequestJwtToken::sendRequest()
{
    nlohmann::json json;

    json["command"] = "request_jwt";
    json["payload"]["type"] = "register";
    //json["payload"]["code"] = "5206";
    json["payload"]["code"] = m_str_register_code.toStdString();
    json["payload"]["reset_password"] = "false";
    json["payload"]["restore"] = "false";
    //json["payload"]["token"] = "35344748D4AD2C82FCA31FE1273540E134857B44BCF869E82B5029C8D0802564";
    json["payload"]["token"] = UserInfo::Instance().getToken();

    emit signalSendToServer(json);
}

bool RequestJwtToken::checkRegisterCode(QString register_code)
{
    if(register_code.length() != LEN_REGISTER_CODE) {
        qWarning() << "Invalid length regoster code";
        return false;
    }

    QRegExp rgx("\\d*");
    if(!rgx.exactMatch(register_code)) {
        qWarning() << "Invalid regoster code is not digits";
        return false;
    }

    setRegisterCode(register_code);
    return true;
}

void RequestJwtToken::setRegisterCode(const QString &register_code)
{
    m_str_register_code = register_code;
}

QString RequestJwtToken::getRegisterCode() const
{
    return m_str_register_code;
}

RequestJwtToken::~RequestJwtToken()
{
    disconnect(this, SIGNAL(signalSendToServer(nlohmann::json)), &Connector::Instance(), SLOT(slotSendToServer(nlohmann::json)));
}
