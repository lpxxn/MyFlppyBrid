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
    rect.setWidth(20);
    rect.setHeight(20);
    rect.setX(-20);
    rect.setY(-20);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(this,SIGNAL(fly()),this,SLOT(updateRale()));
    timer->start(200);

    m_birdImage<<"://Images/bird1.png"<<"://Images/bird2.png"<<"://Images/bird3.png";
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
    this->rale=-30;
}

void FlyBird::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    QPixmap pix;

    static int i=0;
    pix.load(m_birdImage.at(i++));
    if(i>=2)
        i=0;
    painter.setWindow(rect);
    if(rale>=-30&&rale<=90)
    {
        painter.rotate(rale);
        rale+=0.5;
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
    painter.drawPixmap(rect,pix);
}
