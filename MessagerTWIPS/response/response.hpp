#pragma once

#include <QObject>

#include <nlohmann/json.hpp>

class Response : public QObject
{
    Q_OBJECT
public:
    explicit Response(QObject *parent = nullptr);
    Q_DISABLE_COPY(Response)

signals:
    void signalError(QString error);
    void signalOk();

public slots:
    void getJson(const nlohmann::json &json);

};

