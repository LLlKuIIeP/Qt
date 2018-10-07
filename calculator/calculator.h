#pragma once

#include <QWidget>
#include <QStack>

class QLCDNumber;
class QPushButton;

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr);

    QPushButton *createButton(const QString &str);  //создание кнопок калькулятора
    void calculate();   //вычисляет выражения в стеке m_stk

signals:

public slots:
    void slotButtonClicked();   //слот для реакции нажатия на кнопку

private:
    QLCDNumber *m_pcld;     //индикатор, отображение результата
    QStack<QString> m_stk;  //стек для проведения операций вычисления
    QString m_strDispay;
};
