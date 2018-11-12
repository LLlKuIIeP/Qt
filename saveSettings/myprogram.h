#pragma once

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;

class MyProgram : public QWidget {
    Q_OBJECT

public:
    MyProgram(QWidget* pwgt = nullptr);
    virtual ~MyProgram();

    void writeSettings();   //запись настроек
    void readSettings ();   //чтение настроек

public slots:
    void slotCheckBoxClicked();         //устанавливает виджет текстового поля в активное или неак­тивное состояние
    void slotComboBoxActivated(int);    //устанавливает цвет фона и шрифта виджета текстового поля в зависимости от индекса элемента выпадающего списка n

private:
    QSettings m_settings;   //основной класс настроек
    QComboBox *m_pcbo;      //выпадающий список
    QCheckBox* m_pchk;      //флаг
    QTextEdit* m_ptxt;      //виджет тесктового поля
    QLabel* m_plbl;         //виджет надписи
    int m_nCounter;         //количество запусков программы
};
