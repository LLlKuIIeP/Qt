#include "baseresponse.hpp"

bool BaseResponse::getResponse(const nlohmann::json &json)
{
    Q_UNUSED(json)
}

nlohmann::json::const_iterator BaseResponse::findKey(const nlohmann::json &json, const std::string key)
{
    for(auto it = json.begin(); it != json.end(); ++it) {

        if(it.key() == key) {
            return it;
        }

        if(it.value().is_object()) {

            auto res = findKey(it.value(), key);
            if(res.key() == key) {
                return res;
            }
        }
    }

    return json.end();
}
