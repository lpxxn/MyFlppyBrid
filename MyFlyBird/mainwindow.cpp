#include <QMouseEvent>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(WINDOWWHITE,WINDOWHEIGHT);
    m_Bird =new FlyBird(this);
    m_Bird->move(QPoint(60,150));
    m_birdTimer = new QTimer(this);
    connect(m_birdTimer,SIGNAL(timeout()),this,SLOT(BirdFlppy()));
    m_Bird->setRale(-50);
    m_birdTimer->start(20);
    m_birdHeight = 0;
}

void MainWindow::BirdFlppy()
{
    m_Bird->move(m_Bird->pos().x(),m_Bird->pos().y()+ m_birdHeight);
    m_birdHeight=1;
    if(m_Bird->pos().y()+m_Bird->height()>=WINDOWHEIGHT)
    {
        m_Bird->move(m_Bird->pos().x(),WINDOWHEIGHT - m_Bird->height()+5);
        m_birdTimer->stop();
    }

}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    if((event->button()==Qt::LeftButton)&&m_Bird->pos().y()>0)
    {
        m_birdHeight=-6;
        m_birdTimer->setInterval(8);
        emit m_Bird->fly();

    }
}
