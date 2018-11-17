//Листинг 31.1
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMenuBar mnuBar;                                                                //меню верхнего уровня
    QMenu *pmnu = new QMenu("&Menu");                                               //пункт меню верхнего уровня

    pmnu->addAction("&About Qt", &app, SLOT(aboutQt()), Qt::CTRL + Qt::Key_Q);      //горячие клавиши для пункта меню
    pmnu->addSeparator();                                                           //разделительная черта

    QAction *pCheckableAction = pmnu->addAction("&CheckableItem");                  //пункт меню
    pCheckableAction->setCheckable(true);                                           //наличие флага
    pCheckableAction->setChecked(true);                                             //флаг включон

    pmnu->addAction(QPixmap(":/img4.png"), "&IconItem");                            //пункт меню с картинкой

    QMenu *pmnuSubMenu = new QMenu("&SubMenu", pmnu);                               //пункт меню с вложением
    pmnu->addMenu(pmnuSubMenu);                                                     //добавляем в меню вернего уровня
    pmnuSubMenu->addAction("&Test");                                                //подпункт пункта меню

    QAction *pDisabledAction = pmnu->addAction("&DisabledItem");                    //пункт меню
    pDisabledAction->setEnabled(false);                                             //недоступность пункта

    pmnu->addSeparator();                                                           //разделитель

    pmnu->addAction("&Exit", &app, SLOT(quit()));                                   //пункт меню "Выход"

    mnuBar.addMenu(pmnu);                                                           //добавили все пункты меню в меню верхнего уровня
    mnuBar.show();

    return app.exec();
}
