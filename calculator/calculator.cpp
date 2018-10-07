#include <QtWidgets>
#include <QLCDNumber>

#include "calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    m_pcld = new QLCDNumber(12);    //количесво сигментов
    m_pcld->setSegmentStyle(QLCDNumber::Flat);  //задает плоский стиль сегментов
    m_pcld->setMinimumSize(150, 50);    //минимальный размер индикатора

    QChar aButtons[4][4] = {{'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'},
                           };

    QGridLayout *ptopLauout = new QGridLayout;
    ptopLauout->addWidget(m_pcld, 0, 0, 1, 4);
    ptopLauout->addWidget(createButton("CE"), 1 ,3);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ptopLauout->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
    }
    setLayout(ptopLauout);
}

QPushButton *Calculator::createButton(const QString &str) {
    QPushButton *pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pcmd;
}

void Calculator::calculate() {
    qreal fOperand2 = m_stk.pop().toDouble();
    QString strOperation = m_stk.pop();
    qreal fOperand1 = m_stk.pop().toDouble();
    qreal fResult = 0;

    if (strOperation == "+") {
        fResult = fOperand1 + fOperand2;
    }
    else if (strOperation == "-") {
        fResult = fOperand1 - fOperand2;
    }
    else if (strOperation == "*") {
        fResult = fOperand1 * fOperand2;
    }
    else if (strOperation == "/" && static_cast<bool>(fOperand2) ) {
        fResult = fOperand1 / fOperand2;
    }
    else {
         m_stk.clear();
         m_pcld->display("wrong expression");
         return;
    }

    m_strDispay.clear();
    m_pcld->display(fResult);
}

void Calculator::slotButtonClicked() {
    QString str = ((QPushButton*)sender())->text();

    if (str == "CE") {
        m_stk.clear();
        m_strDispay = "";
        m_pcld->display("0");
        return;
    }
    else if (str.contains(QRegExp("[0-9]"))) {
        m_strDispay += str;
        m_pcld->display(m_strDispay.toDouble());
    }
    else if (str == ".") {
        m_strDispay += str;
        m_pcld->display(m_strDispay);
    }
    else {
        if (m_stk.count() > 1) {
            if (str.contains(QRegExp("[\\+\\-\\*\\/]"))) {
                m_stk.pop();
                m_stk.push(str);
                return;
            }
            m_stk.push(QString().setNum(m_pcld->value()));
            calculate();
            m_stk.clear();
            m_stk.push(QString().setNum(m_pcld->value()));
            if (str != "=") {
                m_stk.push(str);
            }
        }
        else {
            m_stk.push(QString().setNum(m_pcld->value()));
            m_stk.push(str);
            m_strDispay = "";
        }
    }
}
