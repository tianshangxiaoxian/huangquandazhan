#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QIcon>
#include <QApplication>
#include"GameSetting.h"
#include"huangquan.h"
#include"score.h"
#include"health.h"
int main(int argc, char *argv[])
{      //创建黄泉战机
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon(":/image/20240507192009.jpg"));
    a.setApplicationDisplayName("牢公你咋莫了");
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
    MainWindow w;
    //w.show();
    return a.exec();
}
