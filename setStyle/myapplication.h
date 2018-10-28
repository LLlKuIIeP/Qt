#pragma once

#include <QWidget>

class MyApplication : public QWidget
{
    Q_OBJECT

public:
    MyApplication(QWidget *parent = nullptr);

public slots:
    void slotChangeStyle(const QString&);
};
