#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>
class Health: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QGraphicsTextItem*parent=nullptr);
    int gethealth();
    void decrease();
    static Health& getInstance(){
        static Health obj;
        return obj;
      }
private:
    void reset();
    int health=3;
};

#endif // HEALTH_H
