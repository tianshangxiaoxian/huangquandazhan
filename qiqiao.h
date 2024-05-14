#ifndef QIQIAO_H
#define QIQIAO_H
#include<QGraphicsPixmapItem>
#include <QObject>

class Qiqiao : public QObject, public QGraphicsPixmapItem
{friend class Huangquan;
    Q_OBJECT
public:
    Qiqiao(QGraphicsPixmapItem*parent=nullptr);
signals:
protected:
     virtual void timerEvent(QTimerEvent *event) override;
};

#endif // QIQIAO_H
