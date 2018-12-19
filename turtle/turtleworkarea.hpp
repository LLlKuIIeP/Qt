#pragma once

#include <QWidget>
#include <QJSEngine>

class QTextEdit;
class Turtle;

class TurtleWorkArea : public QWidget
{
    Q_OBJECT
public:
    explicit TurtleWorkArea(QWidget *parent = nullptr);

signals:

public slots:

private:
    QTextEdit *m_ptxt;
    QJSEngine m_scriptEngine;
    Turtle *m_pTurtle;

private slots:
    void slotEvaluate();
    void slotApplyCode(int n);
};


