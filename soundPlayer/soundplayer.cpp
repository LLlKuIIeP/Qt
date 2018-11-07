#include <QtWidgets>

#include "soundplayer.h"

SoundPlayer::SoundPlayer(QWidget *parent): QWidget(parent) {
    QPushButton *pcmdOpen = new QPushButton("&Open");                   //кнопка Open
    QDial *pdiaVolue = new QDial;                                       //громкость

    m_pcmdPlay = new QPushButton;
    m_pcmdStop = new QPushButton;
    m_psldPosition = new QSlider;
    m_plblCurrent = new QLabel(msecsToString(0));
    m_plblRemain = new QLabel(msecsToString(0));
    m_pmp = new QMediaPlayer;

    m_pcmdPlay->setEnabled(false);                                      //недоступность кнопки
    m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));   //стандартная иконка кнопки

    m_pcmdStop->setEnabled(false);                                      //недоступность кнопки
    m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));   //стандартная иконка кнопки

    m_psldPosition->setRange(0, 0);                                     //начальное состояние ползунка в нуле
    m_psldPosition->setOrientation(Qt::Horizontal);                     //горизонтальное расположение ползунка

    pdiaVolue->setRange(0, 100);                                        //диапозон звука
    int nDefaultVolume = 50;                                            //стартовое значение громкости
    m_pmp->setVolume(nDefaultVolume);
    pdiaVolue->setValue(nDefaultVolume);

    connect(pcmdOpen, SIGNAL(clicked()), SLOT(slotOpen()));
    connect(m_pcmdPlay, SIGNAL(clicked()), SLOT(slotPlay()));
    connect(m_pcmdStop, SIGNAL(clicked()), m_pmp, SLOT(slotStop()));
    connect(pdiaVolue, SIGNAL(valueChanged(int)), m_pmp, SLOT(setValume(int)));
    connect(m_psldPosition, SIGNAL(sliderMoved(int)), SLOT(slotSetMediaPosition(int)));
    connect(m_pmp, SIGNAL(positionChanged(qint64)), SLOT(slotSetSliderPosition(qint64)));
    connect(m_pmp, SIGNAL(durationChanged(qint64)), SLOT(slotSetDuration(qint64)));
    connect(m_pmp, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(slotStatusChanget(QMediaPlayer::State)));

    //первая горизонталь кнопок
    QHBoxLayout *phbxPlayControls = new QHBoxLayout;
    phbxPlayControls->addWidget(pcmdOpen);
    phbxPlayControls->addWidget(m_pcmdPlay);
    phbxPlayControls->addWidget(m_pcmdStop);
    phbxPlayControls->addWidget(pdiaVolue);

    //вторая горизонталь кнопок
    QHBoxLayout *phbxTimeControls = new QHBoxLayout;
    phbxTimeControls->addWidget(m_plblCurrent);
    phbxTimeControls->addWidget(m_psldPosition);
    phbxTimeControls->addWidget(m_plblRemain);

    //
    m_pvbxMainLayout = new QVBoxLayout;
    m_pvbxMainLayout->addLayout(phbxPlayControls);
    m_pvbxMainLayout->addLayout(phbxTimeControls);

    setLayout(m_pvbxMainLayout);
}

QString SoundPlayer::msecsToString(qint64 n) {
    int nHours = (static_cast<int>(n) / (60 * 60 * 1000));
    int nMinutes = ((n % (60 * 60 * 1000)) / (60 * 1000));
    int nSeconds = ((n % (60 * 60 * 1000)) / 1000);

    return QTime(nHours, nMinutes, nSeconds).toString("hh:mm:ss");
}

void SoundPlayer::slotOpen() {
    QString strFile = QFileDialog::getOpenFileName(this, "Open File");

    if(!strFile.isEmpty()) {
        m_pmp->setMedia(QUrl::fromLocalFile(strFile));
        m_pcmdPlay->setEnabled(true);
        m_pcmdStop->setEnabled(true);
    }
}

void SoundPlayer::slotPlay() {
    switch(m_pmp->state()) {
        case QMediaPlayer::PlayingState:
            m_pmp->pause();
            break;
        default:
            m_pmp->play();
            break;
    }
}

void SoundPlayer::slotSetSliderPosition(qint64 n) {
    m_psldPosition->setValue(static_cast<int>(n));

    m_plblCurrent->setText(msecsToString(n));
    int nDuration = m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration - n));
}

void SoundPlayer::slotSetMediaPosition(int n) {
    m_pmp->setPosition(n);
}

void SoundPlayer::slotSetDuration(qint64 n) {
    m_psldPosition->setRange(0, static_cast<int>(n));
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
}

void SoundPlayer::slotStatusChanget(QMediaPlayer::State state) {
    switch(state) {
        case QMediaPlayer::PlayingState:
            m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
            break;
        default:
            m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            break;
    }
}


