#pragma once

#include <QtWidgets>

class ResizeObserver : public QLabel
{
    Q_OBJECT

public:
    ResizeObserver(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent*) override;   //изменение размеров окна
};

