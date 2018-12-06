#include <memory>
#include <array>

#include <QDebug>

#include "response.hpp"

#include "responsetoken.hpp"
#include "responsejwttoken.hpp"
#include "responseupdateuserinfo.hpp"

#define ELEMENTS_TREE 4
const std::array<std::string, ELEMENTS_TREE> arr = {
    "code", "command", "description", "payload"
};

Response::Response(QObject *parent) : QObject(parent)
{}

//FAKE
/*void Response::getJson(const nlohmann::json &json_)
{
    nlohmann::json json;
    json["code"] = 200;
    json["command"] = "profile_update";
    json["description"] = "ok";
    json["payload"] = "";
*/
void Response::getJson(const nlohmann::json &json)
{
    std::unique_ptr<BaseResponse> ptr;

    for(auto &elem : arr) {
        auto it = json.find(elem);
        if(it == json.end()) {
            qWarning() << "Bad response, not find element:" << elem.front();
            return;
        }
    }

    auto it_json_code = json.find("code");
    if(it_json_code.value() != 200) {
        //зауск обработчика ошибок сервера

        //переделать, понять в каком формате прилетает из json.value
        std::string str = json.find("description").value().front();
        QString str2 = str.data();
        emit signalError(str2);
        return;
    }

    auto it_json_description = json.find("description");
    if(it_json_description.value() != "ok") {
        //как-то несогласованно, от сервера 200 а тут что-то есть, отличное от ожидаемого
        return;
    }

    auto it_json_command = json.find("command");
    if(it_json_command.value() == "request_code") {
        ptr = std::move(std::make_unique<ResponseToken>());
    }
    else if(it_json_command.value() == "request_jwt") {
        ptr = std::move(std::make_unique<ResponseJwtToken>());
    }
    else if(it_json_command.value() == "profile_update") {
        ptr = std::move(std::make_unique<ResponseUpdateUserInfo>());
    }

    if(ptr->getResponse(json)) {
        emit signalOk();
    }
}
