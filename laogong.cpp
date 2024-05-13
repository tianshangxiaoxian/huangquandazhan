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
Laogong::Laogong(QGraphicsPixmapItem*parent):QGraphicsPixmapItem(parent)
{//设置图片
setPixmap(QPixmap(":/202405071920ad.png"));
setScale(GameSetting::laogongScale);
//出现位置
int max=GameSetting::SceneWidth-boundingRect().width()*GameSetting::laogongScale;
int Random=QRandomGenerator::global()->bounded(1,max);
setPos(Random,0);
startTimer(GameSetting::laogongTimer);
}
//牢公向前进
void Laogong:: timerEvent(QTimerEvent *){
    //碰撞检测
    QList<QGraphicsItem *> collidingItems=this->collidingItems();
    for(auto item:collidingItems){
        if(typeid(*item)==typeid(Huangquan)){
            Health::getInstance().decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
        if(typeid(*item)==typeid(Bullet)){
            QSound *sound = new QSound(":/badaozhan.wav"); // 创建QSound对象
            sound->play(); // 播放声音
            Score::getInstance().increase();
            scene()->removeItem(item);
            scene()->removeItem(this);
             delete item;
            delete this;

            return;
        }
    }
    setPos(x(),y()+GameSetting::laogongsudu);
    //析构牢公
    if(y()>GameSetting::SceneHeight){
        scene()->removeItem(this);
        delete this;
          return;
    }

}
