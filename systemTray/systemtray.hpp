#pragma once
#include <QLabel>

class QSystemTrayIcon;
class QMenu;

class SystemTray : public QLabel
{
    Q_OBJECT

public:
    SystemTray(QWidget *parent = nullptr);

public slots:
    void slotShowHide();        //
    void slotShowMessage();
    void slotChangeIcon();

protected:
    void closeEvent(QCloseEvent*) override; //перегрузка нужна для работы приложения и после закрытия

private:
    QSystemTrayIcon *m_ptrayIcon;   //нужен для возможности использовать область уведомлений
    QMenu *m_ptrayIconMenu;         //нужен для реализации контекстного меню
    bool m_bIcomSwitcher;           //нужен для смены растровых изображений
};
