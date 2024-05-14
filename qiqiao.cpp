#include "qiqiao.h"
#include "laogong.h"
#include"QPixmap"
#include"GameSetting.h"
#include<QRandomGenerator>
#include<QGraphicsScene>
#include"huangquan.h"
#include"bullet.h"
#include"score.h"
#include"health.h"
#include<QSound>
#include <QMediaPlayer>
#include <QAudioOutput>
#include"bullet1.h"
Qiqiao::Qiqiao(QGraphicsPixmapItem*parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/eatvo1loijcqee7nuixcdrt7c04ve50 (1).png"));
    setScale(GameSetting::laogongScale);
    //出现位置
    int max=GameSetting::SceneWidth-boundingRect().width()*GameSetting::laogongScale;
    int max1=GameSetting::SceneHeight-boundingRect().height()*GameSetting::laogongScale;
    int Random=QRandomGenerator::global()->bounded(1,max);
    int Random1=QRandomGenerator::global()->bounded(1,max1);
    setPos(Random,Random1);
    startTimer(GameSetting::laogongTimer);
}

void Qiqiao::timerEvent(QTimerEvent *event)
{//检查碰撞
    QList<QGraphicsItem *> collidingItems=this->collidingItems();
    for(auto item:collidingItems){
        if(typeid(*item)==typeid(Huangquan)){

            scene()->removeItem(this);
            delete this;
            return;
        }
}}
