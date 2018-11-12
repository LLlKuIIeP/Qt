#include <QtWidgets>
#include <QVideoWidget>

#include "videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent): SoundPlayer(parent) {
    QVideoWidget *pvw = new QVideoWidget;
    pvw->setMinimumSize(300, 300);

    m_pvbxMainLayout->addWidget(pvw);
    m_pmp->setVideoOutput(pvw);
}


