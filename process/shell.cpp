#include <QtWidgets>
#include "shell.hpp"

Shell::Shell(QWidget *parent): QWidget(parent)
{
    m_process = new QProcess(this);
    m_ptxtDisplay = new QTextEdit;

    QLabel *plbl = new QLabel("&Command");

#ifdef Q_OS_WIN
    QString strCommand = "dir";
#else
    QString strCommand = "ls";
#endif

    m_ptxtCommand = new QLineEdit(strCommand);
    plbl->setBuddy(m_ptxtCommand);

    QPushButton *pcmd = new QPushButton("&Enter");

    connect(m_process, SIGNAL(readyReadStandardOutput()), SLOT(slotDataOnStdout()));    //readyReadStandardOutput специальный слот процесса для процесса
                                                                                        //говорит о том, что есть данные для чтения
    connect(m_ptxtCommand, SIGNAL(returnPressed()), SLOT(slotReturnPressed()));

    connect(pcmd, SIGNAL(clicked()), SLOT(slotReturnPressed()));

    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(plbl);
    phbxLayout->addWidget(m_ptxtCommand);
    phbxLayout->addWidget(pcmd);

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_ptxtDisplay);
    pvbxLayout->addLayout(phbxLayout);
    setLayout(pvbxLayout);
}

void Shell::slotDataOnStdout()
{
    m_ptxtDisplay->append(m_process->readAllStandardOutput());
}

void Shell::slotReturnPressed()
{
    QString strCommand = "";

#ifdef Q_OS_WIN
    strCommand = "cmd /C";
#endif
    strCommand += m_ptxtCommand->text();
    m_process->start(strCommand);           //запуск процесса с командой
}


