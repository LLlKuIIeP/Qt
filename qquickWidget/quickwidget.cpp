#include "quickwidget.h"

#include <QQuickItem>
#include <QQmlProperty>

QuickWidget::QuickWidget(QWidget *parent): QQuickWidget(parent)
{
    setSource(QUrl::fromLocalFile(":/Page.qml"));

    QQuickItem *item = rootObject();

    connect(item, SIGNAL(signalOk()), this, SLOT(slotOk()));
}

QuickWidget::~QuickWidget()
{

}

void QuickWidget::slotOk()
{
    qDebug() << "QuickWidget::slotOk";

    QQuickItem *item = rootObject();
    qDebug() << QQmlProperty::read(item, "minimalWidth");
    qDebug() << item->property("minimalWidth");

    QQmlProperty::write(item, "minimalWidth", 200);
    item->setProperty("minimalWidth", 250);
}
