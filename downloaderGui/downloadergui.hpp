#pragma once

#include <QWidget>
#include <QUrl>

class Downloader;
class QProgressBar;
class QLineEdit;
class QPushButton;

class DownloaderGui : public QWidget
{
    Q_OBJECT
public:
    explicit DownloaderGui(QWidget *parent = nullptr);

signals:

public slots:

private:
    Downloader *m_pdl;
    QProgressBar *m_ppb;
    QLineEdit *m_ptxt;
    QPushButton *m_pcmd;

    void showPic(const QString &strFileName);

private slots:
    void slotGo();                                  //осуществляет исполнение загрузки ресурса
    void slotError();                               //вызывается при возникновении ошибки
    void slotDownloadProgress(quint64 nReceived, qint64 nTotal);     //отображает процесс загрузки используя класс QProgressBar
    void slotDone(const QUrl &url, const QByteArray &ba);  //выполняет конечные действия по окончанию самой загрузки
};

