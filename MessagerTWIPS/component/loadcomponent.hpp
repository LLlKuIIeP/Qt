#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

class LoadComponent : public QObject
{
    Q_OBJECT
public:
    explicit LoadComponent(QQmlApplicationEngine *engine, QObject *parent = nullptr);

signals:

public slots:

private:
    QObject *m_pobject;
    QString m_file_name;
    QQmlApplicationEngine *m_pengine;

private slots:
    void slotLoadPage(QString);
};
