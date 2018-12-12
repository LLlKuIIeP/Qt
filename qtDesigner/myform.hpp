#pragma once

#include "ui_MyForm.h"

class MyForm : public QWidget, public Ui::MyForm {
    Q_OBJECT

public:
    MyForm(QWidget *parent = nullptr) : QWidget(parent) {
        setupUi(this);

        connect(m_pcmdReset, SIGNAL(clicked()), this, SLOT(slotReset()));
    }

public slots:
    void slotReset() {
        m_psld->setValue(0);
        m_plcd->display(0);
    }
};
