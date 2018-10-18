#pragma once

#include <QtWidgets>

class MouseObserver : public QLabel
{
    Q_OBJECT

public:
    MouseObserver(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent*) override;    //нажатия на кнопку мыши
    void mouseReleaseEvent(QMouseEvent*) override;  //отпускание кнопки мыши
    void mouseMoveEvent(QMouseEvent*) override;     //перемещение мыши

    void dumpEvent(QMouseEvent*, const QString&);   //выводит информацию о состоянии мыши
    QString modifiersInfo(QMouseEvent*);            //информация о клавишах-модификаторах
    QString buttonsInfo(QMouseEvent*);              //информация о кнопках мыши
};
