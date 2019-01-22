#include <array>

#include <QDebug>
#include "widget.hpp"

//дефолтные точки
constexpr std::array<std::array<double, 2>, 23> arr = {{
    {2, 2}, {4, 8}, {3, 8}, {2.5, 6}, {2, 8}, {1, 8}, {2, 5}, {1, 2},           //У
    {6, 2}, {6, 4.5}, {7.5, 4.5}, {8, 5.5}, {8, 7}, {7.5, 8}, {5 ,8}, {5, 2},   //P
    {10, 2}, {10.5, 4.5}, {11, 2}, {12, 2}, {11, 8}, {10, 8}, {9, 2}            //A
}};

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    /*  Для графика
     * */
    m_p_graphic = new QCustomPlot();

    connect(m_p_graphic, SIGNAL(mousePress(QMouseEvent *)), SLOT(slotMousePress(QMouseEvent *)));
    connect(m_p_graphic, SIGNAL(mouseMove(QMouseEvent *)), SLOT(slotMouseMove(QMouseEvent *)));

    m_p_graphic->xAxis->setRange(0, 12.5);
    m_p_graphic->xAxis->setLabel("X");

    m_p_graphic->yAxis->setRange(0, 10);
    m_p_graphic->yAxis->setLabel("Y");

    m_p_curve = new QCPCurve(m_p_graphic->xAxis, m_p_graphic->yAxis);

    ///дефолтные значения для графика
    QVector<QCPCurveData> vec;
    for(size_t i = 0; i < arr.size(); ++i) {
        vec.push_back(QCPCurveData(i, arr[i][0], arr[i][1]));
    }

    m_p_curve->data()->set(vec, false);

    m_p_curve->setPen(QColor("red"));
    m_p_curve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));  //тип точки и размер
    m_p_graphic->addGraph();
    m_p_graphic->replot();
    /*************************************************************************************************/

    /*  Для таблицы
     * */
    m_p_table_view = new QTableView();
    m_p_table_view->setColumnWidth(0, 100);
    m_p_table_view->setColumnWidth(1, 100);
    m_p_table_view->setFixedWidth(230);

    QStringList strList;
    strList << "X" << "Y";

    QStandardItemModel *model = new QStandardItemModel(arr.size(), 2);
    model->setHorizontalHeaderLabels(strList);
    m_p_table_view->setModel(model);

    ///дефолтные значения для таблицы
    for(size_t i = 0; i < arr.size(); ++i) {
        auto index = m_p_table_view->model()->index(static_cast<int>(i), 0);
        m_p_table_view->model()->setData(index, arr[i][0]);

        index = m_p_table_view->model()->index(static_cast<int>(i), 1);
        m_p_table_view->model()->setData(index, arr[i][1]);
    }

    connect(m_p_table_view->model(), SIGNAL(itemChanged(QStandardItem *)), SLOT(slotItemChanged(QStandardItem *)));
    /*************************************************************************************************/

    ///размещение виджетов
    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(m_p_graphic);
    phbxLayout->addWidget(m_p_table_view);

    setLayout(phbxLayout);
}

Widget::~Widget()
{

}

//определяет, захватим точку или нет
void Widget::slotMousePress(QMouseEvent *me)
{
    double x = m_p_graphic->xAxis->pixelToCoord(me->pos().x());
    double y = m_p_graphic->yAxis->pixelToCoord(me->pos().y());

    for(auto it = m_p_curve->data()->begin(); it != m_p_curve->data()->end(); ++it) {
        if(x > it->key - 0.1 && x < it->key + 0.1) {
            if(y > it->value - 0.1 && y < it->value + 0.1) {
                m_index = it->t;
                ///не понял как сохранить итератор, но думаю это можно
                //m_iterator = it;
                break;
            }
        }
        m_index = -1;

    }

    m_p_graphic->replot();
}

//реагирует на перемещение указателя мыши
void Widget::slotMouseMove(QMouseEvent *me)
{
    if(me->buttons() & Qt::LeftButton) {
        if(m_index >= 0) {
            double x = m_p_graphic->xAxis->pixelToCoord(me->pos().x());
            double y = m_p_graphic->yAxis->pixelToCoord(me->pos().y());

            auto it = m_p_curve->data()->begin();
            for(int i = 0; i < m_index; ++i) {
                ++it;
            }

            it->key = x;
            it->value = y;

//            m_iterator->key = x;
//            m_iterator->value = y;

            for(auto it = m_p_curve->data()->begin(); it != m_p_curve->data()->end(); ++it) {
                qDebug() << it->t << it->key << it->value;
            }

            m_p_graphic->replot();
            updateTable(it->t, it->key, it->value);
        }
    }
}

//по сигналу изменения данных в таблице перерисовывает график
void Widget::slotItemChanged(QStandardItem *item)
{
    auto it = m_p_curve->data()->begin();
    for(int i = 0; i < item->row(); ++i) {
        ++it;
    }

    if(item->column() == 0) {
        it->key = item->index().data().toDouble();
        m_p_graphic->replot();
        return;
    }

    if(item->column() == 1) {
        it->value = item->index().data().toDouble();
        m_p_graphic->replot();
        return;
    }
}

//изменение точки на графике приводит к изменению значения в ячейке таблицы
void Widget::updateTable(const int row, const double x, const double y)
{
    auto x_model = m_p_table_view->model()->index(row, 0);
    auto y_model = m_p_table_view->model()->index(row, 1);

    m_p_table_view->model()->setData(x_model, x);
    m_p_table_view->model()->setData(y_model, y);
}
