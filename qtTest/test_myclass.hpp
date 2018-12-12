#pragma once

#include <QObject>
#include <QtTest>

#include "myclass.hpp"

class Test_MyClass : public QObject
{
    Q_OBJECT
public:
    explicit Test_MyClass(QObject *parent = nullptr);

signals:

public slots:

private slots:
    void min();
    void max();

    void min_data();
    void max_data();
};


