#pragma once

#include <QtWidgets>
#include <QQuickWidget>

class QuickWidget : public QQuickWidget
{
    Q_OBJECT

public:
    QuickWidget(QWidget *parent = nullptr);
    ~QuickWidget();

private slots:
    void slotOk();
};
