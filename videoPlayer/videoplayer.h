#pragma once
#include "../soundPlayer/soundplayer.h"

class VideoPlayer : public SoundPlayer
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
};
