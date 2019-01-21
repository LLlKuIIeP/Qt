#include <QDebug>
#include "table.hpp"

Table::Table(QWidget *parent) : QTableView(parent)
{
    QStringList strList;
    strList << "X" << "Y" << "Z";

    QStandardItemModel *model = new QStandardItemModel(5, 3);
    model->setHorizontalHeaderLabels(strList);

    setModel(model);

    for(size_t i = 0; i < 3; ++i) {
        setColumnWidth(i, 100);
    }

    resize(330, 350);

    connect(this, SIGNAL(clicked(const QModelIndex &)), SLOT(slotClicked(const QModelIndex &)));
    connect(this->model(), SIGNAL(itemChanged(QStandardItem *)), SLOT(slotItemChanged(QStandardItem *)));

    setSelectionMode(QAbstractItemView::ExtendedSelection);
    //setDragDropMode(QAbstractItemView::DragDrop);
    //setDragEnabled(true);
    //viewport()->setAcceptDrops(true);
    //setDropIndicatorShown(true);
}

Table::~Table()
{

}

void Table::keyPressEvent(QKeyEvent *pe)
{
    //qDebug() << "keyPressEvent" << pe->key();
    switch (pe->key()) {
        case Qt::Key_Return : { //какое-то непонятное дело, должно быть по идее Key_Enter
            qDebug() << "keyPressEvent: Enter";
            if(model()->columnCount() == m_column) {
                model()->insertRow(m_row);
            }
            break;
        }
        case Qt::Key_Delete : { //удаляет значения/строки
            if(pe->modifiers() & Qt::ControlModifier) { //удалить строки
                qDebug() << "keyPressEvent: ctrl + Delete";
                m_rows = selectedIndexes().rbegin()->row() - selectedIndexes().begin()->row();

                model()->removeRows(selectedIndexes().begin()->row(), m_rows + 1);
                break;
            }

            //очистить значения
            for(auto &elem : selectedIndexes()) {
                model()->setData(elem, QVariant());
            }

            break;
        }
        case Qt::Key_C : {
            if(pe->modifiers() & Qt::ControlModifier) {
                qDebug() << "keyPressEvent: ctrl + c";

                m_vector.clear();

                m_rows = selectedIndexes().rbegin()->row() - selectedIndexes().begin()->row();
                m_columns = selectedIndexes().rbegin()->column() - selectedIndexes().begin()->column();

                auto modelIndexList = selectedIndexes();
                int idx = 0;

                for(int i = 0; i <= m_rows; ++i) {
                    m_vector.push_back(QVector<QVariant>());

                    for(int j = 0; j <= m_columns; ++j) {
                        m_vector[i].push_back(modelIndexList[idx].data());
                        ++idx;
                    }
                }

                for(auto &elem : m_vector) {
                    for(auto &z : elem) {
                        qDebug() << z;
                    }
                }
            }
            break;
        }
        case Qt::Key_V : {
            if(pe->modifiers() & Qt::ControlModifier) {
                qDebug() << "keyPressEvent: ctrl+v";

                //количество скопированных ячеек рано количеству выделенных ячеек
                if(countCopyItems() == selectedIndexes().count()) {
                    insertItems();
                    break;
                }

                //выделена одна ячейка для вставки
                if(selectedIndexes().size() == 1) {
                    //добаляем нужное количество строк
                    model()->insertRows(findMaximumRow(), m_rows);
                    //заполняем данными таблицу
                    selectedOneCell();
                    break;
                }

                //если скопированных элементов больше чем выделенных, тогда игнорируется часть скопированных элементов
                if(countCopyItems() > selectedIndexes().count()) {
                    funGreater();
                    break;
                }

                //если скопированных элементов меньше чем выделенных, тогда дублируется часть скопированных элементов
                if(countCopyItems() < selectedIndexes().count()) {
                    funLess();
                    break;
                }


            }
            break;
        }
        default: {
            QTableView::keyPressEvent(pe);
        }
    }
}

//заполняет выделенные ячейки
void Table::insertItems()
{
    auto modelIndexList = selectedIndexes();
    int idx = 0;

    for(int i = 0; i < m_vector.size(); ++i) {
        for(int j = 0; j < m_vector[i].size(); ++j) {
            model()->setData(modelIndexList[idx], m_vector[i][j]);
            ++idx;
        }
    }
}

//возвращает максимальный номер строки в выделенной наборе
int Table::findMaximumRow()
{
    int maximum_row = selectedIndexes().begin()->row();

    for(auto &elem : selectedIndexes()) {
        if(elem.row() > maximum_row) {
            maximum_row =  elem.row();
        }
    }

    return ++maximum_row;
}

//заполяет ячейки, основываясь на единственной выбранной
void Table::selectedOneCell()
{
    int row = selectedIndexes().begin()->row();
    int column = selectedIndexes().begin()->column();

    for(int i = 0; i < m_vector.size(); ++i) {
        for(int j = 0; j < m_vector[i].size(); ++j) {
            if(j + column < model()->columnCount()) {
                auto index = model()->index(row, j + column);
                model()->setData(index, m_vector[i][j]);
            }
        }
        ++row;
    }
}

//возвращает количество скорированных элементов
int Table::countCopyItems()
{
    int res = 0;
    for(auto &elem : m_vector) {
        for(auto &next : elem) {
            Q_UNUSED(next)
            ++res;
        }
    }

    return res;
}

void Table::funGreater()
{
    int row_start = selectedIndexes().begin()->row();
    int row_end = selectedIndexes().rbegin()->row();

    int column_start = selectedIndexes().begin()->column();
    int column_end = selectedIndexes().rbegin()->column();

    int i_vec = 0;
    int j_vec = 0;

    for(int i = row_start; i <= row_end; ++i) {
        for(int j = column_start; j <= column_end; ++j) {
            auto index = model()->index(i, j);
            qDebug() << index;
            model()->setData(index, m_vector[i_vec][j_vec]);
            qDebug() << m_vector[i_vec][j_vec];
            ++j_vec;
        }
        ++i_vec;
        j_vec = 0;
    }
}

void Table::funLess()
{
    int row_start = selectedIndexes().begin()->row();
    int row_end = selectedIndexes().rbegin()->row();

    int column_start = selectedIndexes().begin()->column();
    int column_end = selectedIndexes().rbegin()->column();

    int i_vec = 0;
    int j_vec = 0;

    for(int i = row_start; i <= row_end; ++i) {
        for(int j = column_start; j <= column_end; ++j) {
            auto index = model()->index(i, j);
            model()->setData(index, m_vector[i_vec][j_vec]);
            ++j_vec;

            if(j_vec == m_vector[i_vec].size()) {
                j_vec = 0;
            }
        }

        ++i_vec;
        j_vec = 0;

        if(i_vec == m_vector.size()) {
            i_vec = 0;
        }
    }
}


void Table::slotClicked(const QModelIndex &index)
{
    m_row = index.row() + 1;
    m_column = index.column() + 1;
}

void Table::slotItemChanged(QStandardItem *item)
{

}


