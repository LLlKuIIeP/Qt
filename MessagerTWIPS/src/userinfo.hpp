#pragma once

#include <string>

#include <QObject>
#include <QString>
#include <QDebug>

class UserInfo : public QObject
{
    Q_OBJECT
public:
    static UserInfo& Instance(QObject *parent = nullptr);

    Q_INVOKABLE bool writeUserInfoInDB();

    Q_DISABLE_COPY(UserInfo)

    UserInfo(UserInfo&&) = delete;
    UserInfo& operator=(UserInfo&&) = delete;
signals:

public slots:
    void setPhoneNumber(const QString &phone);
    const QString getPhoneNumber() const;

    void setToken(const std::string &token);
    const std::string getToken() const;

    void setJwtToken(const std::string &jwt_token);
    const std::string getJwtToken() const;

    void setUserId(int user_id);
    int getUserId();

    void setUserCountry(const QString &country);
    const QString getUserCountry();

    void setFirstName(const QString &first_name);
    const QString getFirstName();

    void setSurname(const QString &surname);
    const QString getSurname();

    void setNickname(const QString &nickname);
    const QString getNickname();

private:
    QString m_str_phone_number;
    QString m_str_first_name;
    QString m_str_surname;
    QString m_str_nickname;
    QString m_str_country;
    std::string m_str_token;
    std::string m_str_jwt_token;
    int m_str_user_id;


    explicit UserInfo(QObject *parent = nullptr);
};

