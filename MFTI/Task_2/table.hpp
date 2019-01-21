#pragma once

#include <QtWidgets>

class Table : public QTableView
{
    Q_OBJECT

public:
    Table(QWidget *parent = nullptr);
    ~Table();

    void keyPressEvent(QKeyEvent *pe) override;

protected:
    //void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

public slots:
     void slotClicked(const QModelIndex &index);
     void slotItemChanged(QStandardItem *item);

private:
    int m_row;
    int m_column;

    QVector<QVector<QVariant>> m_vector;
    int m_rows{0};
    int m_columns{0};

    void insertItems();
    int findMaximumRow();
    void selectedOneCell();
    int countCopyItems();
    void funGreater();
    void funLess();
};


