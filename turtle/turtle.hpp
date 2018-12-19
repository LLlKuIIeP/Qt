#pragma once

#include <QtWidgets>

class Turtle : public QWidget
{
    Q_OBJECT

public:
    Turtle(QWidget *parent = nullptr);

public slots:
    void forward(int n);            //переместит "черепаху" вперед на n пикселов с рисованием следа
    void back(int n);               //переместить "черепаху" назад на n символов с рисованием следа
    void left(int nAngle);          //поворот "черепахи" влево на угол nAngle
    void right(int nAngle);         //поворот "черепахи" вправо на угол nAngle
    void reset();                   //очистка экрана и установка "черепахи" в середину

protected:
    void init();
    void paintEvent(QPaintEvent *ev) override;

private:
    QPixmap m_pix;
    QPainter m_painter;
};

