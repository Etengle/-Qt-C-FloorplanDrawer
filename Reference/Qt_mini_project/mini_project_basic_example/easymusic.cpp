#include "easymusic.h"
#include <stdlib.h>
easyMusic::easyMusic(char *path, int volume, int isLoop)
{    
    media=new QMediaPlayer;
    media->setMedia(QUrl::fromLocalFile(path));
    media->setVolume(volume);
    isConnectBefore=0;
    if(isLoop){
        setPlayInLoop();
        isConnectBefore=1;
    }


}
easyMusic::~easyMusic()
{

}
void easyMusic::setPlayOneTime(){
    disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));    
}
void easyMusic::setPlayInLoop(){
    connect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
}
void easyMusic::stop(){

    isConnectBefore = disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
    media->stop();
}
void easyMusic::pause(){
    isConnectBefore = disconnect( media, SIGNAL(stateChanged(QMediaPlayer::State)), media, SLOT(play()));
    media->pause();
}
void easyMusic::play(){
    if(isConnectBefore)
        setPlayInLoop();
    else
        setPlayOneTime();
    media->play();
}
void easyMusic::setVolume(int V){
    media->setVolume(V);
}
void easyMusic::setMusicPath(char *p){
    media->setMedia(QUrl::fromLocalFile(p));
}
void easyMusic::mute(bool m){
    media->setMuted(m);
}
void easyMusic::louderOrlower(bool L){
    if(L==true)
        media->setVolume(media->volume()+10);
    else
        media->setVolume(media->volume()-10);

}
