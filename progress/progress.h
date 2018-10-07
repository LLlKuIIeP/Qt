#pragma once

#include <QWidget>

class QProgressBar;

class Progress : public QWidget
{
    Q_OBJECT

public:
    Progress(QWidget *parent = 0);

public slots:
    void slotStep();
    void slotReset();

private:
    QProgressBar *m_pprb;
    int m_nStep{0};
};
