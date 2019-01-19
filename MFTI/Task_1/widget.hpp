#pragma once

#include <QtWidgets>
#include <QtCharts>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

protected:
     void timerEvent(QTimerEvent *ev) override; //переопределенный метод из QObject, нужен для работы QBasicTimer

private slots:
    void slotStart();   //слот для кнопки "Старт"
    void slotPause();   //слот для кнопки "Пауза"
    void slotStop();    //слот для кнопки "Стоп"



private:
    int m_x{0};         //координато по оси Х

    std::mt19937 m_generator;   //генератор случайных чисел
    std::uniform_int_distribution<int> m_urd_axis_y{0, 100};    //установка генерации в диапозоне от 0 до 100 в целых числах

    QChart *m_pChart;           //график
    QScatterSeries *m_pSeries;  //набор точек
    QChartView *m_pchart_view;  //отображение графика
    QBasicTimer *m_pTimer;      //таймер

    void updateChartView(); //обновление графика
};


