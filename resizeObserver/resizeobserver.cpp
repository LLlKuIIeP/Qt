#include "resizeobserver.h"

ResizeObserver::ResizeObserver(QWidget *parent): QLabel(parent) {
    setAlignment(Qt::AlignCenter);  //центровка всей выводимой информации на экран
}

/*virtual*/void ResizeObserver::resizeEvent(QResizeEvent *pe) {
    setText(QString("Resize") +
            "\n width()=" + QString::number(pe->size().width()) +
            "\n heigth()=" + QString::number(pe->size().height())
            );
}


