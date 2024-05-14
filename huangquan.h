#ifndef HUANGQUAN_H
#define HUANGQUAN_H
#include<QGraphicsPixmapItem>
#include <QObject>

class Huangquan: public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void zhanjijia();
    Huangquan(QGraphicsPixmapItem*parent=nullptr);
    double   zhanji=0;
    // QGraphicsItem interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
private:
    void laogongchuxian();
     void gameOver();
     void qiqiaochuxian();
    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private:
    bool playing=true;
    QGraphicsTextItem*messagetem=nullptr;
};

#endif // HUANGQUAN_H
