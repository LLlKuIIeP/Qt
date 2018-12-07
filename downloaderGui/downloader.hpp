#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class Downloader : public QObject
{
    Q_OBJECT

public:
    Downloader(QObject *parent = nullptr);

    void download(const QUrl &url);

    ~Downloader();

signals:
    void downloadProgress(quint64, qint64);
    void done(const QUrl&, const QByteArray&);
    void error();

private:
    QNetworkAccessManager *m_pnam;

private slots:
    void slotFinished(QNetworkReply *pnr);
};


