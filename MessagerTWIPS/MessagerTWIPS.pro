QT += qml quick network sql
CONFIG += c++1z

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    src/phone.cpp \
    connector/connector.cpp \
    request/baserequest.cpp \
    request/requestregister.cpp \
    component/loadcomponent.cpp \
    response/response.cpp \
    response/baseresponse.cpp \
    response/responsetoken.cpp \
    request/requestjwttoken.cpp \
    response/responsejwttoken.cpp \
    src/country.cpp \
    connector/connectorsqlite.cpp \
    response/responseupdateuserinfo.cpp \
    src/forendpage.cpp \
    src/userinfo.cpp \
    request/requestupdateuserinfo.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    main.qml \
    Page1.qml \
    Page2.qml \
    Page3.qml \
    Page4.qml \
    Page5.qml \
    Page6.qml

HEADERS += \
    src/phone.hpp \
    connector/connector.hpp \
    request/baserequest.hpp \
    request/requestregister.hpp \
    component/loadcomponent.hpp \
    response/response.hpp \
    response/baseresponse.hpp \
    response/responsetoken.hpp \
    request/requestjwttoken.hpp \
    response/responsejwttoken.hpp \
    src/country.hpp \
    connector/connectorsqlite.hpp \
    response/responseupdateuserinfo.hpp \
    src/forendpage.hpp \
    src/userinfo.hpp \
    request/requestupdateuserinfo.hpp
