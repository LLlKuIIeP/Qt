#pragma once

#include <QTcpSocket>

#include <nlohmann/json.hpp>

#include "response/response.hpp"

class QString;

class Connector : public QObject
{
    Q_OBJECT
public:
    static Connector& Instance(QObject *parent = nullptr);

    Q_DISABLE_COPY(Connector)

    Connector(Connector&&) = delete;
    Connector& operator=(Connector&&) = delete;

    Response *getResponse();
signals:
    void signalSendJsonToResponse(const nlohmann::json &json);
    void signalEmptyResponseFromServer(QString);

public slots:
    void slotSendToServer(nlohmann::json json);

private slots:
    void slotConnected();
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);


private:
    QTcpSocket *m_ptcp_socket;
    Response m_response;

    explicit Connector(QObject *parent = nullptr);

};
