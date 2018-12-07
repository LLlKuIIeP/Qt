#include <QtWidgets>

#include "downloadergui.hpp"
#include "downloader.hpp"

DownloaderGui::DownloaderGui(QWidget *parent) : QWidget(parent)
{
    m_pdl = new Downloader(this);
    m_ppb = new QProgressBar;
    m_ptxt = new QLineEdit;
    m_pcmd = new QPushButton(tr("Go"));

    QString strDownloadLink = "http://qt-book.com/pic.jpg";

    m_ptxt->setText(strDownloadLink);

    connect(m_pcmd, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_pdl, SIGNAL(downloadProgress(quint64, qint64)), SLOT(slotDownloadProgress(quint64, qint64)));
    connect(m_pdl, SIGNAL(done(const QUrl&, const QByteArray&)), SLOT(slotDone(const QUrl&, const QByteArray&)));

    QGridLayout *pLayout = new QGridLayout;
    pLayout->addWidget(m_ptxt, 0, 0);
    pLayout->addWidget(m_pcmd, 0, 1);
    pLayout->addWidget(m_ppb, 1, 0);
    setLayout(pLayout);
}

void DownloaderGui::showPic(const QString &strFileName)
{
    QPixmap pix(strFileName);
    pix = pix.scaled(pix.size() / 2,                //уменьшаем размер в 2 раза
                     Qt::IgnoreAspectRatio,
                     Qt::SmoothTransformation);     //режим сглаживания

    QLabel *plbl = new QLabel;
    plbl->setPixmap(pix);
    plbl->setFixedSize(pix.size());
    plbl->show();
}

void DownloaderGui::slotGo()
{
    m_pdl->download(QUrl(m_ptxt->text()));
}

void DownloaderGui::slotError()
{
    QMessageBox::critical(0, tr("Error"), tr("An error while download is occured"));
}

void DownloaderGui::slotDownloadProgress(quint64 nReceived, qint64 nTotal)
{
    if(nTotal <= 0) {
        slotError();
        return;
    }

    m_ppb->setValue(100 * nReceived / nTotal);
}

void DownloaderGui::slotDone(const QUrl &url, const QByteArray &ba)
{
    QString strFileName = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/" + url.path().section('/', -1);

    QFile file(strFileName);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(ba);
        file.close();

        if(strFileName.endsWith(".jpg") || strFileName.endsWith(".png")) {
            showPic(strFileName);
        }
    }
}
