#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "downloader.hpp"

Downloader::Downloader(QObject *parent)
    : QObject(parent)
{
    m_pnam = new QNetworkAccessManager(this);

    connect(m_pnam, SIGNAL(finished(QNetworkReply*)), SLOT(slotFinished(QNetworkReply*)));
}

void Downloader::download(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *pnr = m_pnam->get(request);

    connect(pnr, SIGNAL(downloadProgress(quint64, qint64)), SLOT(downloadProgress(quint64, qint64)));
}

Downloader::~Downloader()
{

}

void Downloader::slotFinished(QNetworkReply *pnr)
{
    if(pnr->error() != QNetworkReply::NoError) {
        emit error();
    }
    else {
        emit done(pnr->url(), pnr->readAll());
    }

    pnr->deleteLater();
}
