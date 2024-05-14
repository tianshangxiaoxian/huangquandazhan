#ifndef BULLET1_H
#define BULLET1_H
#include<QGraphicsPixmapItem>
#include <QObject>

class Bullet1 : public QObject,public  QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet1(QGraphicsPixmapItem*parent=nullptr);

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // BULLET_H
