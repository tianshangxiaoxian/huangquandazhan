#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include<QGraphicsTextItem>
class Score :public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsTextItem*parent=nullptr);
    void increase();
    static Score& getInstance(){
        static Score obj;
        return obj;
      }
    int score=0;
private:
void reset();//重置函数


};
#endif // SCORE_H
