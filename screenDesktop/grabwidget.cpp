#include <QtWidgets>
#include "grabwidget.hpp"

GrabWidget::GrabWidget(QWidget *parent): QWidget(parent)
{
    resize(640, 480);

    m_plbl = new QLabel;

    QPushButton *pcmd = new QPushButton("Capture Screen");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotGrabScreen()));

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmd);
    pvbxLayout->addWidget(m_plbl);
    setLayout(pvbxLayout);
}

void GrabWidget::slotGrabScreen()
{
    QDesktopWidget *pwgt = QApplication::desktop();             //указатель на весь объет экрана из статического метода
    QPixmap pic = QPixmap::grabWindow(pwgt->screen()->winId()); //объект QPixmap позволяет получить растровое изображение виджета
                                                                //с помощью метода grabWindow, в который надо передать идентификатор
                                                                //окна виджета, для этого вызывается screen - получить указатель на виджет
                                                                //и методом winId получить тот самый идентификатор
    m_plbl->setPixmap(pic.scaled(m_plbl->size()));
}
