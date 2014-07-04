#include "moveground.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
MoveGround::MoveGround(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(400,60);

    m_bgX = 0;
    m_timer=new QTimer();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(groundMove()));
    play();
}

MoveGround::~MoveGround()
{
    delete m_timer;
}

void MoveGround::play()
{
    m_timer->start(50);
}

void MoveGround::stop()
{
    m_timer->stop();
}

void MoveGround::groundMove()
{
    --m_bgX;
    if(m_bgX<=-40)
        m_bgX=0;
    update();
}

void MoveGround::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load("://Images/ground.png");
    painter.drawPixmap(m_bgX,0,450,60,pixmap);
}
