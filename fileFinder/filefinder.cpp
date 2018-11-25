#include <QtWidgets>
#include "filefinder.hpp"

FileFinder::FileFinder(QWidget *parent): QWidget(parent)
{
    m_ptxtDir = new QLineEdit(QCoreApplication::applicationDirPath());  //инициализация абсолютным путем приложения applicationDirPath
    m_ptxtMask = new QLineEdit("*");                                    //фильтр для найденных файлов
    m_ptxtResult = new QTextEdit;                                       //результат поиска

    QLabel *plblDir = new QLabel("&Directory");
    QLabel *plblMask = new QLabel("&Mask");
    QPushButton *pcmdDir = new QPushButton(QPixmap(":/fileopen.png"), "");
    QPushButton *pcmdFind = new QPushButton("&Find");

    connect(pcmdDir, SIGNAL(clicked()), SLOT(slotBrowse()));
    connect(pcmdFind, SIGNAL(clicked()), SLOT(slotFind()));

    plblDir->setBuddy(m_ptxtDir);
    plblMask->setBuddy(m_ptxtMask);

    QGridLayout *pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(plblDir, 0, 0);
    pgrdLayout->addWidget(plblMask, 1, 0);
    pgrdLayout->addWidget(m_ptxtDir, 0, 1);
    pgrdLayout->addWidget(m_ptxtMask, 1, 1);
    pgrdLayout->addWidget(pcmdDir, 0, 2);
    pgrdLayout->addWidget(pcmdFind, 1, 2);
    pgrdLayout->addWidget(m_ptxtResult, 2, 0, 1, 3);
    setLayout(pgrdLayout);
}

void FileFinder::start(const QDir &dir)
{
    QApplication::processEvents();                                                      //чтобы интефейс процесс не зависал на поиске
    QStringList listFiles = dir.entryList(m_ptxtMask->text().split(" "), QDir::Files);  //получает список файлов текущего каталога, в соответствии с маской

    foreach(QString file, listFiles) {
        m_ptxtResult->append(dir.absoluteFilePath(file));                               //добавление абсолютного пути к файлу
    }

    QStringList listDir = dir.entryList(QDir::Dirs);
    foreach(QString subdir, listDir) {
        if(subdir == "." || subdir == "..") {
            continue;
        }
        start(QDir(dir.absoluteFilePath(subdir)));
    }
}

void FileFinder::slotBrowse()
{
    QString str = QFileDialog::getExistingDirectory(0, "Select a Directory", m_ptxtDir->text());

    if(!str.isEmpty()) {
        m_ptxtDir->setText(str);
    }
}

void FileFinder::slotFind()
{
    start(QDir(m_ptxtDir->text()));
}


