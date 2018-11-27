#pragma once

#include <QWidget>

class QTimer;

class MyWorker : public QObject
{
    Q_OBJECT

public:
    MyWorker(QObject *parent = nullptr);

signals:
    void valueChanged(int);
    void finished();

public slots:
    void slotDoWork();

private slots:
    void setNextValue();

private:
    int m_nValue;
    QTimer *m_ptimer;
};

