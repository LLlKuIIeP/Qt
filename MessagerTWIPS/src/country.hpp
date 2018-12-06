#pragma once

#include <QObject>
#include <QStringList>

class Country : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList m_arr READ getArr CONSTANT)

public:
    explicit Country(QObject *parent = nullptr);

    Q_INVOKABLE void countryNameChanged(QString country);
    Q_INVOKABLE void saveCountry(QString country);
    Q_INVOKABLE bool saveUserInfo();

    QStringList getArr();

signals:

public slots:

private:
    QStringList m_arr;
    QString m_str_country_selected;
};

