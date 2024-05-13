#include "zhando.h"
#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QIcon>
#include <QApplication>
#include"GameSetting.h"
#include"huangquan.h"
#include"score.h"
#include"health.h"
#include<QtMultimedia>
Zhando::Zhando(QWidget *parent) : QMainWindow(parent)
{   
    this->setFixedSize(GameSetting::SceneWidth,GameSetting::SceneHeight);
        //设置图标
        this->setWindowIcon(QPixmap(":/20240507192009.png"));
        //设置标题
        this->setWindowTitle("选择关卡");

    QApplication::setWindowIcon(QIcon(":/20240507192009.png"));
    //创建黄泉
Huangquan*huangquan=new Huangquan;
    //创建场景
    QGraphicsScene*Scene=new QGraphicsScene;
    Scene->addItem(huangquan);
    Scene->setSceneRect(0,0,GameSetting::SceneWidth,GameSetting::SceneHeight);
    Scene->setBackgroundBrush(QImage(":/image/20240507185818.jpg"));
    //创建健康文字
    Scene->addItem(&Health::getInstance());
    //创建分数文字
   Scene->addItem(&Score::getInstance());
    QGraphicsView view(Scene);
    view.setFixedSize(GameSetting::SceneWidth,GameSetting::SceneHeight);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();
}

void Zhando::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
        QPixmap pix;
        pix.load(":/image/20240507185818.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
