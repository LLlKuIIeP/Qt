#pragma once
#include <QWidget>

class QLabel;

class GrabWidget : public QWidget
{
    Q_OBJECT

public:
    GrabWidget(QWidget *parent = nullptr);

public slots:
    void slotGrabScreen();

private:
    QLabel *m_plbl;
};
