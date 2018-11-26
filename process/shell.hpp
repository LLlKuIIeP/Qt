#pragma once

#include <QWidget>

class QProcess;
class QLineEdit;
class QTextEdit;

class Shell : public QWidget
{
    Q_OBJECT

public:
    Shell(QWidget *parent = nullptr);

public slots:
    void slotDataOnStdout();
    void slotReturnPressed();

private:
    QProcess *m_process;
    QLineEdit *m_ptxtCommand;
    QTextEdit *m_ptxtDisplay;
};
