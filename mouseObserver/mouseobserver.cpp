#include "mouseobserver.h"

MouseObserver::MouseObserver(QWidget *parent): QLabel(parent) {
    setAlignment(Qt::AlignCenter);  //центровка всей выводимой информации на экран
    setText("Mouse interactions\n(Press a mouse button)");
}

/*virtual*/ void MouseObserver::mousePressEvent(QMouseEvent *pe) {
    dumpEvent(pe, "Mouse Pressed");
}

/*virtual*/ void MouseObserver::mouseReleaseEvent(QMouseEvent *pe) {
    dumpEvent(pe, "Mouse Released");
}

/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent *pe) {
    dumpEvent(pe, "Mouse Is Moving");
}

void MouseObserver::dumpEvent(QMouseEvent *pe, const QString &strMsg) {
    setText(strMsg +
            "\n buttons()=" + buttonsInfo(pe) +
            "\n x()=" + QString::number(pe->x()) +
            "\n y()=" + QString::number(pe->y()) +
            "\n globalX=" + QString::number(pe->globalX()) +
            "\n globalY=" + QString::number(pe->globalY()) +
            "\n modifiers()=" + modifiersInfo(pe)
            );
}

QString MouseObserver::modifiersInfo(QMouseEvent *pe) {
    QString strModifiers;

    if (pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shift ";
    }
    if (pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control ";
    }
    if (pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt ";
    }

    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent *pe) {
    QString strButtons;

    if (pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if (pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    if (pe->buttons() & Qt::MidButton) {
        strButtons += "Middle ";
    }

    return strButtons;
}
