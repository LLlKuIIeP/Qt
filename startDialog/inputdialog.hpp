#pragma once

#include <QDialog>

class QLineEdit;

class InputDialog : public QDialog {
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = nullptr);

    QString firstName() const;
    QString lastName() const;

private:
    QLineEdit *m_ptxtFirstName;
    QLineEdit *m_ptxtLastName;
};
