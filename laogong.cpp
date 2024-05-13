#include "laogong.h"
#include"QPixmap"
#include"GameSetting.h"
#include<QRandomGenerator>
#include<QGraphicsScene>
#include"huangquan.h"
#include"bullet.h"
#include"score.h"
#include"health.h"
Laogong::Laogong(QGraphicsPixmapItem*parent):QGraphicsPixmapItem(parent)
{//设置图片
setPixmap(QPixmap(":/image/0240507190735.jpg"));
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
