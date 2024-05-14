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
#include<QtMultimedia>
#include <QSound>
#include <QMediaPlayer>
#include <QAudioOutput>
#include"bullet1.h"
#include"qiqiao.h"
#include"score.h"
using namespace GameSetting;
Huangquan::Huangquan(QGraphicsPixmapItem *parent):QGraphicsPixmapItem(parent)
{//给黄泉附图片
    setPixmap(QPixmap(":/20240507192009.png"));
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
        if(1>zhanji>0){  Bullet*bullet=new Bullet;
          bullet->setPos(x()+boundingRect().width()*huangquanScale/2-bullet->boundingRect().width()*BulletScale/2,
                         y());
          scene()->addItem(bullet);
          //播放音效
          QSound *sound = new QSound(":/zidanfashe.MP3"); // 创建QSound对象
          sound->play(); // 播放声音
          //QMediaPlayer fashe ;
          //fashe.setVideoOutput(&QAudioOutput());
          //fashe.setVolume(":/zidanfashe.MP3");
          //fashe.play();
        }
if(zhanji>1){Bullet1*bullet1=new Bullet1;
    bullet1->setPos(x()+boundingRect().width()*huangquanScale/2-bullet1->boundingRect().width()*Bullet1Scale/2,
                   y());
    scene()->addItem(bullet1);
    zhanji--;
}

    break;
}
    }
//实现牢公出现
void Huangquan:: laogongchuxian(){

    Laogong*laogong=new Laogong;
    scene()->addItem(laogong);

}
//实现零食出现
void Huangquan:: qiqiaochuxian(){

    Qiqiao*qiqiao=new Qiqiao;
    scene()->addItem(qiqiao);

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
     laogongchuxian();
     zhanji+=0.1;}
//qiqiaochuxian();}
if(Health::getInstance().gethealth()<=0){
    gameOver();
}
}
