#include "bullet.h"
#include"GameSetting.h"
#include<QGraphicsScene>
Bullet::Bullet(QGraphicsPixmapItem*parent):QGraphicsPixmapItem(parent)
{
setPixmap(QPixmap(":/20240507190656.png"));
this->setScale(GameSetting::BulletScale);
startTimer(GameSetting::BulletTimer);}
void Bullet::timerEvent(QTimerEvent *)
{
    setPos(x(),y()-GameSetting::bulletspeed);
  if(y()+boundingRect().height()<0){
scene()->removeItem(this);
        delete this;
}
}
