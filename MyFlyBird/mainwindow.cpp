

#include "mainwindow.h"
#include <QMouseEvent>
#include <QListIterator>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(WINDOWWHITE,WINDOWHEIGHT);
    m_Bird =new FlyBird(this);
    m_Bird->move(QPoint(60,150));
    m_birdTimer = new QTimer(this);
    connect(m_birdTimer,SIGNAL(timeout()),this,SLOT(BirdFlppy()));
    m_Bird->setRale(-50);
    //m_birdTimer->start(20);
    m_birdHeight = 0;


    initBirdFlyData();
    QList<double>::iterator end= m_birdFlyData.end();
    while(m_birdFlyIterator!=end)
    {

        ++m_birdFlyIterator;
        qDebug()<<*m_birdFlyIterator;
    }

//    for(m_birdFlyIterator;m_birdFlyIterator!=m_birdFlyData.end();++m_birdFlyIterator)
//    {
//        qDebug()<<*m_birdFlyIterator;
//    }

}

void MainWindow::initBirdFlyData()
{
    //m_birdFlyData<<-3<<-4<<-3<<-2<<-1<<-1<<0<<1<<1<<2<<2<<2<<3<<3;
    m_birdFlyData.push_back(-3);
    m_birdFlyData.push_back(-4);
    m_birdFlyData.push_back(-2);
    m_birdFlyData.push_back(-1);
    m_birdFlyData.push_back(-2);
    m_birdFlyData.push_back(0);
    m_birdFlyData.push_back(1);
    m_birdFlyData.push_back(1);
    m_birdFlyData.push_back(2);
    m_birdFlyData.push_back(2);
    m_birdFlyData.push_back(3);
    m_birdFlyData.push_back(3);
    m_birdFlyIterator=m_birdFlyData.begin();

}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    if((event->button()==Qt::LeftButton)&&m_Bird->pos().y()>0)
    {
        m_birdFlyIterator=m_birdFlyData.begin();
        m_birdTimer->setInterval(8);
        emit m_Bird->fly();

    }
}

void MainWindow::BirdFlppy()
{
    qDebug()<<*m_birdFlyIterator;
    m_Bird->move(m_Bird->pos().x(),m_Bird->pos().y()+ *m_birdFlyIterator);
    if(m_birdFlyIterator!=m_birdFlyData.end())
    {

        ++m_birdFlyIterator;
    }
    else
    {
        m_birdFlyIterator=m_birdFlyData.end();
    }
    if(m_Bird->pos().y()+m_Bird->height()>=WINDOWHEIGHT)
    {
         qDebug()<<"stop";
        m_Bird->move(m_Bird->pos().x(),WINDOWHEIGHT - m_Bird->height()+5);
        m_birdTimer->stop();
    }

}
