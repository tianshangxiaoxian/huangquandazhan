#include "huangquan.h"
#include<QPixmap>
#include"GameSetting.h"
#include<QKeyEvent>
#include"laogong.h"
#include<QGraphicsScene>
#include"bullet.h"
#include"health.h"
#include<QGraphicsTextItem>
#include<QFontMetrics>
using namespace GameSetting;
Huangquan::Huangquan(QGraphicsPixmapItem *parent):QGraphicsPixmapItem(parent)
{//给黄泉附图片
    setPixmap(QPixmap(":/image/20240507192009.jpg"));
    setScale(huangquanScale);
    //黄泉所在的位置
    setPos(SceneWidth/2-boundingRect().width()*huangquanScale/2,
           SceneHeight-boundingRect().height()*huangquanScale);
    setFlag(QGraphicsItem::ItemIsFocusable);//可以获得焦点
    setFocus();//获得焦点
    startTimer(500);

}
//实现动起来
void Huangquan::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        if(pos().x()>0)
            setPos(x()-huangquanspeed,y());
    break;
    case Qt::Key_Right:
        if(pos().x()<SceneWidth-boundingRect().width()*huangquanScale)
            setPos(x()+huangquanspeed,y());
    break;
    case Qt::Key_Up:
        if(pos().y()>0)
            setPos(x(),y()-huangquanspeed);
   break;
    case Qt::Key_Down:
        if(pos().y()<SceneHeight-boundingRect().height()*huangquanScale)
            setPos(x(),y()+huangquanspeed);
   break;
    case Qt::Key_Space:
        Bullet*bullet=new Bullet;
        bullet->setPos(x()+boundingRect().width()*huangquanScale/2-bullet->boundingRect().width()*BulletScale/2,
                       y());
        scene()->addItem(bullet);
        //播放音效
    break;
}
    }
//实现牢公出现
void Huangquan:: laogongchuxian(){

    Laogong*laogong=new Laogong;
    scene()->addItem(laogong);

}

void Huangquan::gameOver()
{
    playing=false;
    for(auto item:scene()->items()){
        if(typeid (*item)==typeid(Laogong)){
            scene()->removeItem(item);
            delete item;
        }
    }
    if(!messagetem){
        messagetem=new QGraphicsTextItem;
        scene()->addItem(messagetem);
        QString message("Game Over");
        messagetem->setPlainText(message);
        messagetem->setDefaultTextColor(Qt::red);
        QFont font("Courier New",32,QFont::Bold);
        messagetem->setFont(QFont("Courier New",32,QFont::Bold));
        QFontMetrics fm(font);
        messagetem->setPos(GameSetting::SceneWidth/2-fm.horizontalAdvance(message)/2,
                           GameSetting::SceneHeight/2-fm.horizontalAdvance(message)/2);
    }else{
        messagetem->show();
    }
}
void Huangquan::timerEvent(QTimerEvent *event){
if(playing){
     laogongchuxian();}
if(Health::getInstance().gethealth()<=0){
    gameOver();
}
}
