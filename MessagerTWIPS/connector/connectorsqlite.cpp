#include <QDebug>
#include "connectorsqlite.hpp"

ConnectorSQLite& ConnectorSQLite::Instance(QString user, QObject *parent)
{
    static ConnectorSQLite *connectorSQLite = nullptr;
    if(connectorSQLite == nullptr) {
        connectorSQLite = new ConnectorSQLite(user, parent);
    }

    return *connectorSQLite;
}

bool ConnectorSQLite::upsertUserInfo(const int user_id, QString jwt_token, QString first_name, QString phone, QString surname, QString nickname, QString country)
{
    if(!m_db.open()) {
        qWarning() << "Cannot open database:" << m_db.lastError();
        qWarning() << "Error:" << m_db.lastError().text();
        return false;
    }

    if(!createTableUserInfo()) {
        return false;
    }

    QString str = "INSERT INTO UserInfo (user_id, jwt_token, first_name, phone, surname, nickname, country) "
                    "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7'); ";

    QString str_query = str.arg(QString::number(user_id))
                           .arg(jwt_token)
                           .arg(first_name)
                           .arg(phone)
                           .arg(surname)
                           .arg(nickname)
                           .arg(country);

    /*-------SELECT-------*/
    selectUserInfo();

    QSqlQuery query;
    if(!query.exec(str_query)) {

    /*-------UPDATE-------*/
        QString str2 = "UPDATE UserInfo SET "
                                   "jwt_token='%1', "
                                   "first_name='%2', "
                                   "phone='%3', "
                                   "surname='%4', "
                                   "nickname='%5', "
                                   "country='%6' "
                        "WHERE user_id=%7;";

        QString str_query2 = str2.arg(jwt_token)
                                   .arg(first_name)
                                   .arg(phone)
                                   .arg(surname)
                                   .arg(nickname)
                                   .arg(country)
                                   .arg(QString::number(user_id));

        if(!query.exec(str_query2)) {
            qWarning() << "Cannot open database:" << m_db.lastError();
            qWarning() << "Error:" << m_db.lastError().text();
            return false;
        }
    }

    /*-------SELECT-------*/
    selectUserInfo();

    return true;
}

ConnectorSQLite::ConnectorSQLite(QString &user, QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(user);

    m_db.setUserName("user");
    m_db.setHostName("vbox");
    m_db.setPassword("1234");

    if(!m_db.open()) {
        qWarning() << "Cannot open database:" << m_db.lastError();
        qWarning() << "Error:" << m_db.lastError().text();
    }
}

bool ConnectorSQLite::createTableUserInfo()
{
    if(auto list_tables(getTables()); findTable(list_tables, "UserInfo")) {
        return true;
    }

    QString str = "CREATE TABLE UserInfo ( "
                  "user_id INTEGER PRIMARY KEY NOT NULL, "
                  "jwt_token VARCHAR(1000) NOT NULL, "
                  "first_name VARCHAR(35) NOT NULL, "
                  "phone VARCHAR(15) NOT NULL, "
                  "surname VARCHAR(35), "
                  "nickname VARCHAR(35), "
                  "country VARCHAR(30) "
                  ");";

    QSqlQuery query;
    if(!query.exec(str)) {
        qWarning() << "Unable to create a table";
        return false;
    }

    return true;
}

const QStringList ConnectorSQLite::getTables()
{
    QStringList list_tables = m_db.tables();

    foreach(QString lst, list_tables) {
        qDebug() << "Table:" << lst;
    }

    return list_tables;
}

bool ConnectorSQLite::findTable(const QStringList &list_tables, const QString table_name)
{
    for(auto &elem : list_tables) {
        if(elem == table_name) {
            return true;
        }
    }
    return false;
}

void ConnectorSQLite::selectUserInfo()
{
    QString str = "SELECT * FROM UserInfo; ";

    QSqlQuery query;
    query.exec(str);

    QSqlRecord record = query.record();
    qDebug() << str;

    while(query.next()) {
        int id = query.value(record.indexOf("user_id")).toInt();
        QString str_jwt_token = query.value(record.indexOf("jwt_token")).toString();
        QString str_first_name = query.value(record.indexOf("first_name")).toString();
        QString str_phone = query.value(record.indexOf("phone")).toString();
        QString str_surname = query.value(record.indexOf("surname")).toString();
        QString str_nickname = query.value(record.indexOf("nickname")).toString();
        QString str_country = query.value(record.indexOf("country")).toString();

        qDebug() << id << str_jwt_token << str_first_name << str_phone << str_surname << str_nickname << str_country;
    }
}
