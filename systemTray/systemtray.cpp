#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

#include "systemtray.hpp"

SystemTray::SystemTray(QWidget *parent): QLabel("<H1>Application Window</H1>", parent), m_bIcomSwitcher(false)
{
    setWindowTitle("System Tray");

    QAction *pactShowHide = new QAction("&Show/Hide Application Window", this);
    connect(pactShowHide, SIGNAL(triggered()), SLOT(slotShowHide()));

    QAction *pactShowMessage = new QAction("&Show Message", this);
    connect(pactShowMessage, SIGNAL(triggered()), SLOT(slotShowMessage()));

    QAction *pactChangeIcon = new QAction("&Change Icon", this);
    connect(pactChangeIcon, SIGNAL(triggered()), SLOT(slotChangeIcon()));

    QAction *pactOuit = new QAction("&Quit", this);
    connect(pactOuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    m_ptrayIconMenu = new QMenu(this);
    m_ptrayIconMenu->addAction(pactShowHide);
    m_ptrayIconMenu->addAction(pactShowMessage);
    m_ptrayIconMenu->addAction(pactChangeIcon);
    m_ptrayIconMenu->addAction(pactOuit);

    m_ptrayIcon = new QSystemTrayIcon(this);
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    m_ptrayIcon->setToolTip("Sysytem Tray");

    slotChangeIcon();       //установка растрового изображения

    m_ptrayIcon->show();    //добавляет растровое изображение
}

void SystemTray::slotShowHide()
{
    setVisible(!isVisible());
}

void SystemTray::slotShowMessage()
{
    m_ptrayIcon->showMessage("For your information", "You have selected the \"Show Message!\" option", QSystemTrayIcon::Information, 3000);
}

void SystemTray::slotChangeIcon()
{
    m_bIcomSwitcher = !m_bIcomSwitcher;
    QString strPixmapName = m_bIcomSwitcher ? ":/images/img1.png" : ":/images/img2.png";
    m_ptrayIcon->setIcon(QPixmap(strPixmapName));
}

void SystemTray::closeEvent(QCloseEvent *pe)
{
    if(m_ptrayIcon->isVisible()) {
        hide();
    }
}

