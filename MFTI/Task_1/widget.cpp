#include <QDebug>

#include "widget.hpp"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //инициализация генератора случайных чисел
    m_generator.seed(time(0));

    //минимальный таймер
    m_pTimer = new QBasicTimer();

    //сам график
    m_pChart = new QChart();

    //набор точек для графика
    m_pSeries = new QScatterSeries();
    ///m_pSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);    //по умолчанию итак QScatterSeries::MarkerShapeCircle
    m_pChart->legend()->hide();

    //прикрепил набор точек к графику
    m_pChart->addSeries(m_pSeries);

    //ось Х
    QValueAxis *axis_x = new QValueAxis();
    axis_x->setTickCount(21);
    axis_x->setRange(0, 100);
    axis_x->setTitleText("Time seconds");
    m_pChart->addAxis(axis_x, Qt::AlignBottom); //расположение оси
    m_pSeries->attachAxis(axis_x);              //связь точек и оси

    //ось Y
    QValueAxis *axis_y = new QValueAxis();
    axis_y->setTickCount(21);
    axis_y->setRange(0, 100);
    axis_y->setTitleText("Value");
    m_pChart->addAxis(axis_y, Qt::AlignLeft);
    m_pSeries->attachAxis(axis_y);

    //отображение для графика
    m_pchart_view = new QChartView(m_pChart);

    ///*****набор кнопок управления*****
    QPixmap pix_start(":/image/button_start.png");
    QPushButton *p_button_start = new QPushButton();
    p_button_start->setIcon(pix_start);
    p_button_start->setIconSize(QSize(30, 30));
    connect(p_button_start, SIGNAL(clicked()), SLOT(slotStart()));

    QPixmap pix_pause(":/image/button_pause.png");
    QPushButton *p_button_pause = new QPushButton();
    p_button_pause->setIcon(pix_pause);
    p_button_pause->setIconSize(QSize(30, 30));
    connect(p_button_pause, SIGNAL(clicked()), SLOT(slotPause()));

    QPixmap pix_stop(":/image/button_stop.png");
    QPushButton *p_button_stop = new QPushButton();
    p_button_stop->setIcon(pix_stop);
    p_button_stop->setIconSize(QSize(30, 30));
    connect(p_button_stop, SIGNAL(clicked()), SLOT(slotStop()));
    ///-----------------------------------

    ///размещение виджетов
    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(p_button_start);
    phbxLayout->addWidget(p_button_pause);
    phbxLayout->addWidget(p_button_stop);

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_pchart_view);
    pvbxLayout->addLayout(phbxLayout);

    setLayout(pvbxLayout);
}

void Widget::timerEvent(QTimerEvent *ev)
{
    Q_UNUSED(ev)

    qDebug() << "timerEvent";
    int y = m_urd_axis_y(m_generator);  //координаты рандомной точки по оси Y
    qDebug() << y;

    //для того, чтобы график рисовался циклически в диапозоне от 0 до 100 значений
    if(m_x > 100) {
        m_x = 0;
    }

    //добавление точки во множество
    m_pSeries->append(m_x++, y);

    //обновление отображения
    updateChartView();
}

void Widget::slotStart()
{
    qDebug() << "Start";
    if(!m_pTimer->isActive()) {
        m_pTimer->start(1000, this);
    }
}

void Widget::slotPause()
{
    qDebug() << "Pause";
    m_pTimer->stop();
}

void Widget::slotStop()
{
    qDebug() << "Stop";
    m_pTimer->stop();

    m_pSeries->clear();
    m_x = 0;

    updateChartView();
}

void Widget::updateChartView()
{
    m_pchart_view->update();
}
