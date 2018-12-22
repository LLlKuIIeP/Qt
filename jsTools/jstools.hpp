#pragma once

#include <QtWidgets>

class JSTools : public QObject
{
    Q_OBJECT

public:
    JSTools(QWidget *parent = nullptr);

public slots:
    void print(const QString &str);
    void alert(const QString strMessage);
    void quitApplication();
    QStringList dirEntryList(const QString strDir, const QString strExt);

};


