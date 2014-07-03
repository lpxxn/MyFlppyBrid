#include "mainwindow.h"
#include <QMouseEvent>

#include <QDebug>
#include <QPushButton>
#include "ctime"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(WINDOWWHITE,WINDOWHEIGHT);
    this->setStyleSheet("background-image: url(://Images/bg.png)");
    //管道
    initPipes();
    createPipes();
    m_PiperTimer = new QTimer(this);
    connect(m_PiperTimer,SIGNAL(timeout()),this,SLOT(pipeManage()));
    connect(m_PiperTimer,SIGNAL(timeout()),this,SLOT(collisionDetect()));

    //小鸟
    m_Bird =new FlyBird(this);
    InitBird();
    m_birdTimer = new QTimer(this);
    connect(m_birdTimer,SIGNAL(timeout()),this,SLOT(birdFlppy()));


    m_birdHeight = 0;

    initBirdFlyData();

    start_Button=new QPushButton(this);
    start_Button->setStyleSheet
            ("QPushButton {border-image: url(://Images/replay.png);}");
    start_Button->setFixedSize(140,80);
    start_Button->move((WINDOWWHITE-start_Button->width())/2,WINDOWHEIGHT/2);
    connect(start_Button,SIGNAL(clicked()),this,SLOT(startGame()));
}

void MainWindow::InitBird()
{
    m_Bird->move(QPoint(70,150));
    m_Bird->setRale(-50);
}

void MainWindow::initBirdFlyData()
{
    m_birdFlyData<<-3<<-3<<-3<<-3
                 <<-4<<-4<<-4<<-4<<-4
                 <<-3<<-3<<-3<<-3
                 <<-2<<-2<<-2<<-2<<-2<<-2
                 <<-1<<-1<<-1<<-1<<-1<<-1<<-1<<-1
                 <<0<<0<<0
                 <<1<<1<<1<<1
                 <<2<<2<<2<<2<<3;

    m_birdFlyIterator=m_birdFlyData.begin();
    m_birdFlyIteratorEnd = m_birdFlyData.end();
    --m_birdFlyIteratorEnd;
}


void MainWindow::mousePressEvent(QMouseEvent * event)
{
    if((event->button()==Qt::LeftButton)&&m_Bird->pos().y()>0&&!start_Button->isVisible())
    {
        m_birdFlyIterator=m_birdFlyData.begin();
        emit m_Bird->fly();
    }
}

void MainWindow::birdFlppy()
{
    m_Bird->move(m_Bird->pos().x(),m_Bird->pos().y()+ *m_birdFlyIterator);
    if(m_birdFlyIterator<m_birdFlyIteratorEnd)
    {
        ++m_birdFlyIterator;
    }
    else
    {
        m_birdFlyIterator=m_birdFlyIteratorEnd;
    }
    if(m_Bird->pos().y()+m_Bird->height()>=WINDOWHEIGHT)
    {         
        m_Bird->move(m_Bird->pos().x(),WINDOWHEIGHT - m_Bird->height()+5);
        gameOver();
    }
}

void MainWindow::startGame()
{
    InitBird();

    start_Button->setVisible(false);
    int timeIter=8;
    m_birdTimer->start(timeIter);
    m_PiperTimer->start(timeIter);
}

void MainWindow::initPipes()
{
    m_PipeSpacing = 150;
    for(int i=0;i<m_PipesCount;i++) {
        m_Pipes.push_back(new BlockPipe(this));
    }
}

void MainWindow::createPipes()
{
    qsrand(time(NULL));
    int pipeStartX=500;  //起始的管子
    int pipY;
    for(int i=0;i<m_PipesCount;i++) {
        pipY = qrand()%150;
        m_Pipes[i]->move(pipeStartX+i*m_PipeSpacing,pipY-140);
    }
    m_lastPipeIndex = m_Pipes.count()-1;
}

void MainWindow::pipeManage()
{
    int pipY;

    for(int i =0; i<m_PipesCount;i++) {
        m_Pipes[i]->move(m_Pipes[i]->pos().x()-1,m_Pipes[i]->pos().y());
        if(m_Pipes[i]->pos().x()<-60) {
            pipY = qrand()%150;
            m_Pipes[i]->move(m_Pipes[m_lastPipeIndex]->pos().x()+m_PipeSpacing,pipY-140);
            m_lastPipeIndex=i;
        }
    }
}

void MainWindow::collisionDetect()
{
    int birdX = m_Bird->pos().x();
    for(int i=0;i<m_PipesCount;i++) {
        int pipeX=m_Pipes[i]->x();
        if(birdX>=pipeX&&birdX+m_Bird->width()<=pipeX+m_Pipes[i]->width()) {
            int pipHeihgt = m_Pipes[i]->getPipeHeight()+m_Pipes[i]->pos().y();
            if(m_Bird->pos().y()<=(pipHeihgt)||m_Bird->pos().y()>=(pipHeihgt+ m_Pipes[i]->getPipeGap())){
                gameOver();
                break;
            }
        }
    }
}

void MainWindow::gameOver()
{
    m_birdTimer->stop();
    m_PiperTimer->stop();
    createPipes();
    start_Button->setVisible(true);

}

MainWindow::~MainWindow()
{
    qDeleteAll(m_Pipes);
    m_Pipes.clear();
    delete m_birdTimer;
    delete m_PiperTimer;
}

