#include <QGuiApplication>

#include "component/loadcomponent.hpp"
#include "src/phone.hpp"
#include "request/requestregister.hpp"
#include "request/requestjwttoken.hpp"
#include "response/response.hpp"
#include "src/country.hpp"
#include "request/requestupdateuserinfo.hpp"
#include "src/userinfo.hpp"
#include "src/forendpage.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Phone>("Phone", 1, 0, "Phone"); //добавляет модуль в qml
    qmlRegisterType<RequestRegister>("RequestRegister", 1, 0, "RequestRegister");
    qmlRegisterType<RequestJwtToken>("RequestJwtToken", 1, 0, "RequestJwtToken");
    qmlRegisterType<Response>("Response", 1, 0, "Response");
    qmlRegisterType<Country>("Country", 1, 0, "Country");
    qmlRegisterType<RequestUpdateUserInfo>("RequestUpdateUserInfo", 1, 0, "UpdateUserInfo");
    qmlRegisterType<ForEndPage>("ForEndPage", 1, 0, "ForEndPage");

    QQmlApplicationEngine engine;
    LoadComponent load(&engine);


    return app.exec();
}
