#pragma once

#include <QObject>
#include <QtSql>

class ConnectorSQLite : public QObject
{
    Q_OBJECT
public:
    static ConnectorSQLite& Instance(QString user = "user", QObject *parent = nullptr);

    Q_DISABLE_COPY(ConnectorSQLite)

    ConnectorSQLite(ConnectorSQLite&&) = delete;
    ConnectorSQLite& operator=(ConnectorSQLite&&) = delete;

    bool upsertUserInfo(const int user_id,
                       QString jwt_token,
                       QString first_name,
                       QString phone = "",
                       QString surname = "",
                       QString nickname = "",
                       QString country = ""
                       );

signals:

public slots:

private:
    QSqlDatabase m_db;

    explicit ConnectorSQLite(QString &user, QObject *parent = nullptr);

    bool createTableUserInfo();
    const QStringList getTables();
    bool findTable(const QStringList &list_tables, const QString table_name);
    void selectUserInfo();
    bool insertUserInfo(const int user_id, QString jwt_token, QString first_name, QString phone, QString surname, QString nickname, QString country);
};

