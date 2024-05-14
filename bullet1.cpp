#include "bullet1.h"
#include"GameSetting.h"
#include<QGraphicsScene>

Bullet1::Bullet1(QGraphicsPixmapItem*parent):QGraphicsPixmapItem(parent)
{
setPixmap(QPixmap(":/zhanji2.png"));
this->setScale(GameSetting::Bullet1Scale);
startTimer(GameSetting::BulletTimer);}
void Bullet1::timerEvent(QTimerEvent *)
{
    setPos(x(),y()-GameSetting::bulletspeed);
  if(y()+boundingRect().height()<0){
scene()->removeItem(this);
        delete this;
}
}
