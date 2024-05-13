#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"mypushbutton.h"
#include <QPushButton>
#include"zhando.h"
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //配置菜单
    //设置窗口大小
    setFixedSize(500,950);
    //设置图标
    setWindowIcon(QIcon(":/20240507192009.png"));
    setWindowTitle("斩大公");
    //连接退出
     connect(ui->actionquit,&QAction::triggered,[=](){this->close();});
//战斗界面
//Zhando*zhando=new Zhando;
//开始按钮
MyPushButton *startBtn = new MyPushButton(":/image/kaishitubiao.png");
  startBtn->setParent(this);
   startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.5);
   connect(startBtn,&MyPushButton::clicked,[=](){
          startBtn->zoom1(); //向下跳跃
          startBtn->zoom2(); //向上跳跃
          //延时0.5秒后 进入选择场景
                  //QTimer::singleShot(500, this,[=](){
                  //    this->hide();
                  //  zhando->show();
                  });
//});
}

void MainWindow:: paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/ceaa2ffe88a6a8c80e3a6abda38f176.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
MainWindow::~MainWindow()
{
    delete ui;
};

