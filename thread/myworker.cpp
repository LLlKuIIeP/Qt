#include <QTimer>
#include "myworker.hpp"

MyWorker::MyWorker(QObject *parent): QObject(parent), m_nValue(10)
{
    m_ptimer = new QTimer(this);
    connect(m_ptimer, SIGNAL(timeout()), SLOT(setNextValue()));     //чтобы таймер отправлял сигналы в слот
}

void MyWorker::slotDoWork()
{
    m_ptimer->start(1000);                                          //через сколько таймеру отправлять сигналы
}

void MyWorker::setNextValue()
{
    emit valueChanged(--m_nValue);

    if(!m_nValue) {
        m_ptimer->stop();                                           //как только отсчитали 5 секунд останавливаем таймер
        emit finished();                                            //останавливаем поток
    }
}

