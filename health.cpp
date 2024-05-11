#include "health.h"
#include <QGraphicsTextItem>
#include<QFont>
Health::Health(QGraphicsTextItem *parent):QGraphicsTextItem (parent)
{
    reset();
}

int Health::gethealth()
{
    return health;
}

void Health::decrease()
{
    --health;
    setPlainText("健康值"+QString::number(health));
}

void Health::reset()
{
health=3;
setPlainText("健康值"+QString::number(health));
setDefaultTextColor(Qt::blue);
setFont(QFont("Courier New",16,QFont::Bold));
setPos(x(),32);
}
