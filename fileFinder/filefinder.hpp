#pragma once

#include <QWidget>
class QDir;
class QLineEdit;
class QTextEdit;


class FileFinder : public QWidget
{
    Q_OBJECT

public:
    FileFinder(QWidget *parent = nullptr);

protected:
    void start(const QDir&);

public slots:
    void slotBrowse();  //диалоговое окно выбра каталога для поиска
    void slotFind();    //запускает поиск

private:
    QLineEdit *m_ptxtDir;
    QLineEdit *m_ptxtMask;
    QTextEdit *m_ptxtResult;
};
