#ifndef LAOGONG_H
#define LAOGONG_H
#include<QGraphicsPixmapItem>
#include <QObject>

class Laogong :public QObject, public QGraphicsPixmapItem
{friend class Score;
    Q_OBJECT
public:
    Laogong(QGraphicsPixmapItem*parent=nullptr);
    ~Laogong(){
    }
    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // LAOGONG_H
