#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <QString>
#include <QDataStream>

#include <QDebug>

#include "connector.hpp"
#include "response/response.hpp"

#define LENGTH 11

Connector::Connector(QObject *parent) : QObject(parent), m_response()
{
    m_ptcp_socket = new QTcpSocket(this);
    m_ptcp_socket->connectToHost("staging.ma3ka.com", 6000);
qDebug() << "Connector";// << parent->objectName();
    connect(m_ptcp_socket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_ptcp_socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(slotError(QAbstractSocket::SocketError)));
    connect(m_ptcp_socket, SIGNAL(readyRead()), SLOT(slotReadyRead()));

    connect(this, SIGNAL(signalSendJsonToResponse(const nlohmann::json&)), &m_response, SLOT(getJson(const nlohmann::json&)), Qt::DirectConnection);
    connect(this, SIGNAL(signalEmptyResponseFromServer(QString)), &m_response, SIGNAL(signalError(QString)));
}

Connector &Connector::Instance(QObject *parent)
{
    static Connector *connector = nullptr;
    if(connector == nullptr) {
        connector = new Connector(parent);
    }

    return *connector;
}

Response *Connector::getResponse()
{
    return &m_response;
}

void Connector::slotConnected()
{
    qDebug() << "Connector::slotConnected: Received the connected signal";
}

void Connector::slotReadyRead()
{
    QDataStream in(m_ptcp_socket);
    in.setVersion(QDataStream::Qt_5_10);

    //bytesAvaalable - возвращает количество байт доступных для чтения

    if(m_ptcp_socket->bytesAvailable() < LENGTH) {
        qWarning() << "Input block size less minimal size";
        return;
    }

    std::unique_ptr<char[]> size(new char[LENGTH]);
    auto read = in.readRawData(size.get(), LENGTH);
    if(read < LENGTH) {
        qWarning() << "Cannot read block length";
        return;
    }

    int length = atoi(size.get());
    if(length > 0) {
        std::vector<uint8_t> vec_masgpack;
        vec_masgpack.resize(length);
qDebug() << length;

        for(auto &elem : vec_masgpack) {
            in >> elem;
        }

        nlohmann::json json;
        json = nlohmann::json::from_msgpack(vec_masgpack);
qDebug() <<"Connector::slotReadyRead";
std::string s = json.dump(4);
std::cout << s << std::endl;

        emit signalSendJsonToResponse(json);
    }
    else {
        emit signalEmptyResponseFromServer("Server return empty response");
    }
}

void Connector::slotError(QAbstractSocket::SocketError err)
{
    QString error = "Error ";
    if(err == QAbstractSocket::HostNotFoundError) {
        error += "The host was not found.";
    }
    else if(err == QAbstractSocket::RemoteHostClosedError) {
        error += "The remote host is closed.";
    }
    else if(err == QAbstractSocket::ConnectionRefusedError) {
        error += "The connection was refused.";
    }
    else {
        error += QString(m_ptcp_socket->errorString());
    }

    qDebug() << error;
}
//FAKE
/*void Connector::slotSendToServer(nlohmann::json json_)
{
    nlohmann::json json;
    json["command"] = "request_code";
    json["payload"]["phone"] = "71234567890";
    json["payload"]["type"] = "register";
*/
void Connector::slotSendToServer(nlohmann::json json)
{
qDebug() <<"Connector::slotSendToServer";
std::string s = json.dump(4);
std::cout << s << std::endl;

    QByteArray arr;
    QDataStream out(&arr, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    std::vector<uint8_t> vec_masgpack = nlohmann::json::to_msgpack(json);
    uint64_t size_pack; //размер пакета
    size_pack = static_cast<uint64_t>(vec_masgpack.size());

    QString str;
    str = QString::number(size_pack);
    while(str.size() < LENGTH) {
        str.push_front("0");
    }
    out.writeRawData(str.toStdString().data(), LENGTH);

    for(auto &elem : vec_masgpack) {
        out << quint8(elem);
    }

    m_ptcp_socket->write(arr);
}
