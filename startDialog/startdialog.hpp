#pragma once

#include <QtWidgets>
#include "inputdialog.hpp"

class StartDialog : public QPushButton {
    Q_OBJECT

public:
    StartDialog(QWidget *parent = nullptr);

public slots:
    void slotButtonClicked();
};

