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
private:
void reset();//重置函数
int score=0;

};
#endif // SCORE_H
