#pragma once

#include <QtWidgets>

#include "qcustomplot.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slotMousePress(QMouseEvent *me);
    void slotMouseMove(QMouseEvent *me);
    void slotItemChanged(QStandardItem *item);

private:
    QCustomPlot *m_p_graphic;
    QCPCurve *m_p_curve;
    QCPCurveData *m_curve_data;
    ///QVector<QCPCurveData>::iterator m_iterator;  ///не получилась затея с сохранением итератора
    int m_index;

    QTableView *m_p_table_view;

    void updateTable(const int row, const double x, const  double y);
};


