#include "score.h"
#include<QFont>
Score::Score(QGraphicsTextItem *parent):QGraphicsTextItem{parent}
{
reset();
}
void Score::reset(){
    score=0;
    setPlainText("分数："+QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Courier New",16,QFont::Bold));
}
void Score::increase(){
    ++score;
    setPlainText("分数："+QString::number(score));
}
