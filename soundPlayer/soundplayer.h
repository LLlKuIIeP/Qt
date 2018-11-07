#pragma once

#include <QWidget>
#include <QMediaPlayer>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

class SoundPlayer : public QWidget
{
    Q_OBJECT

public:
    SoundPlayer(QWidget *parent = nullptr);

protected:
    QMediaPlayer *m_pmp;
    QVBoxLayout *m_pvbxMainLayout;

private:
    QPushButton *m_pcmdPlay;
    QPushButton *m_pcmdStop;
    QSlider *m_psldPosition;
    QLabel *m_plblCurrent;
    QLabel *m_plblRemain;

    QString msecsToString(qint64);

private slots:
    void slotOpen();                                //открытие файлов
    void slotPlay();                                //управляет воспроизведением
    void slotSetSliderPosition(qint64);             //устанавливает позицию ползунка и время воспроизведения
    void slotSetMediaPosition(int);                 //устанавливает позицию воспроизведенияв классе QMediaPlayer
    void slotSetDuration(qint64);                   //общее время воспроизведения файла
    void slotStatusChanget(QMediaPlayer::State);    //получает статус класса QMediaPlayer
};
