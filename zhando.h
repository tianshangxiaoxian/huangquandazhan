#ifndef ZHANDO_H
#define ZHANDO_H

#include <QMainWindow>

class Zhando : public QMainWindow
{
    Q_OBJECT
public:
    explicit Zhando(QWidget *parent = nullptr);
void paintEvent(QPaintEvent*);
signals:

};

#endif // ZHANDO_H
