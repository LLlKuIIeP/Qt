#pragma once

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT

public:
    void run();

signals:
    void progress(int);
};
