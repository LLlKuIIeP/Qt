#pragma once

#include <QObject>

class MouseFilter : public QObject
{
    Q_OBJECT

public:
    MouseFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject*, QEvent*);
};


