#include <QStringList>
#include <QPainter>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include "flybird.h"

FlyBird::FlyBird(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(35,35);
    //setMaximumSize(35,35);
    //setMinimumSize(35,35);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(this,SIGNAL(fly()),this,SLOT(updateRale()));
    timer->start(200);

}

FlyBird::~FlyBird()
{

}

void FlyBird::setRale(int rale)
{
    this->rale = rale;
}

void FlyBird::play()
{
    timer->start();
}

void FlyBird::stop()
{
    timer->stop();
}

void FlyBird::updateRale()
{
    ztr=rale;
    this->rale=-30;
    x=0;
    zt=1;

}

void FlyBird::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://Images/bird1.png");

    QRect rect;
    rect.setWidth(20);
    rect.setHeight(20);
    rect.setX(-20);
    rect.setY(-20);
    painter.setWindow(rect);

    if(zt==1) {
        painter.rotate(ztr);
        ztr-=10;
        if(ztr<=30) {
            zt=0;
        }
    }
    else
    {
        if(rale>=-30&&rale<=90)
        {
            painter.rotate(rale);
            if(rale<10)
            {
                rale=0.01*x*x-30;
                x+=1;
            }
            else
            {
                rale+=2;
            }
        }
        else if(rale>=90)
        {
            rale=90;
            painter.rotate(rale);
        }
        else if(rale<-30)
        {
            painter.rotate(0);
        }
    }
    painter.rotate(0);
    //qDebug()<<"rect size"<<rect.width()<<rect.height();
    painter.drawPixmap(rect,pix);
}
