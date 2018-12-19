#include "turtle.hpp"

Turtle::Turtle(QWidget *parent): QWidget(parent), m_pix(400, 400), m_painter(&m_pix)
{
    setFixedSize(m_pix.size());
    init();
}

void Turtle::forward(int n)
{
    m_painter.drawLine(0, 0, n, 0);
    m_painter.translate(n, 0);
    repaint();                              //на самом деле это вызов QWidget::repaint();
}

void Turtle::back(int n)
{
    m_painter.drawLine(0, 0, -n, 0);
    m_painter.translate(-n, 0);
    repaint();
}

void Turtle::left(int nAngle)
{
    m_painter.rotate(-nAngle);
}

void Turtle::right(int nAngle)
{
    m_painter.rotate(nAngle);
}

void Turtle::reset()
{
    m_painter.resetTransform();
    init();
    repaint();
}

void Turtle::init()
{
    m_pix.fill(Qt::yellow);                 //закрашивает фон в желтый
    m_painter.translate(rect().center());   //смещение начала координат нашей "черепахи" в центр
    m_painter.rotate(-90);                  //поворот её на 90 градусов
}

void Turtle::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)

    QPainter painter(this);
    painter.drawPixmap(rect(), m_pix);
}
