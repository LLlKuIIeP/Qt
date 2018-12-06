#pragma once

#include <QObject>
#include <QString>
#include <QDebug>

class Phone : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_country_code READ getCountryCode WRITE setCountryCode NOTIFY signalCountryCodeChanged)

public:
    explicit Phone(QObject *parent = nullptr);

    Q_INVOKABLE bool checkAndSavePhone(QString country, QString phone);
    Q_INVOKABLE bool countryNameChanged(QString country);
    Q_INVOKABLE const QString getFullPhoneNumber() const;

    QString getCountryCode() const;
    void setCountryCode(const QString &country_code);

signals:
    void signalCountryCodeChanged();

public slots:

private:
    QString m_country_code;
    QString m_country_name;
    QString m_phone_number;

    bool checkNubmer(QString &phone, const quint16 &lenght);
    void savePhoneNumber(QString &phone);
    void saveCountryCode(const QString &country_code);
    void saveCountryName(QString &country);
};

