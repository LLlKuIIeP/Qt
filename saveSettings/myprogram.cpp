#include <QtWidgets>
#include "myprogram.h"

MyProgram::MyProgram(QWidget* pwgt/*=0*/): QWidget(pwgt), m_settings("BHV", "MyProgram") {  //иницалазация настрок BVH - фирма, MyProgram - название продукта
    m_plbl = new QLabel;
    m_ptxt = new QTextEdit;
    m_pcbo = new QComboBox;
    m_pchk = new QCheckBox("DisaЫe edit");

    m_pcbo->addItem("Classic");     //опции расцветки тестового поля
    m_pcbo->addItem("Borland");     // ----- // -----

    connect(m_pchk, SIGNAL(clicked()), SLOT(slotCheckBoxClicked()));
    connect(m_pcbo, SIGNAL(activated(int)), SLOT(slotComboBoxActivated(int)));

    readSettings();

    //Layout setup
    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    QHBoxLayout *phbxLayout = new QHBoxLayout;

    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    phbxLayout->setSpacing(15);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addWidget(m_plbl);
    pvbxLayout->addWidget(m_ptxt);
    phbxLayout->addWidget(m_pcbo);
    phbxLayout->addWidget(m_pchk);
    pvbxLayout->addLayout(phbxLayout);
    setLayout(pvbxLayout);
}

void MyProgram::readSettings() {

    m_settings.beginGroup("/Settings");                                 //префикс ключа настроек
        QString strText = m_settings.value("/text", "").toString();     //переменной strText присваивается значение ключа /text, если ключа нет, то вернет второй параметр - ""
        int nWidth = m_settings.value("/width", width ()).toInt();
        int nHeight = m_settings.value("/height", height()).toInt();
        int nComboItem = m_settings.value("/highlight", 0).toInt();
        bool bEdit = m_settings.value("/edit", false).toBool();

        m_nCounter = m_settings.value("/counter", 1).toInt();

        QString str = QString().setNum(m_nCounter++);
        m_plbl->setText("This program has been started" + str +" times");

        m_ptxt->setPlainText(strText);
        resize(nWidth, nHeight);

        m_pchk->setChecked(bEdit);
        slotCheckBoxClicked();

        m_pcbo->setCurrentIndex(nComboItem);
        slotComboBoxActivated(nComboItem);
    m_settings.endGroup();                                              //снять префикс ключа
}

void MyProgram:: writeSettings() {
    m_settings .beginGroup ("/Settings");
    m_settings.setValue ("/counter", m_nCounter);
    m_settings.setValue("/text", m_ptxt->toPlainText()) ;
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings .setValue("/highlight", m_pcbo->currentIndex());
    m_settings.setValue("/edit", m_pchk->isChecked());
    m_settings.endGroup();
}

void MyProgram::slotCheckBoxClicked() {
    m_ptxt->setEnabled(!m_pchk->isChecked());
}

void MyProgram::slotComboBoxActivated(int n) {
    QPalette pal = m_ptxt->palette( ) ;
    pal.setColor(QPalette::Active, QPalette::Base, n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active, QPalette::Text, n ? Qt::yellow : Qt::black);
    m_ptxt->setPalette(pal);
}

MyProgram::~MyProgram() {
    writeSettings();
    /*
    АДЕКВАТНАЯ ЗАМЕНА ДЕСТРУКТОРА
    Вместо деструктора можно воспользоваться методом обработки события
    closeEvent(), который вызывается при закрытии окна виджета.
    */
}
