#include "mainwindow.h"
#include <QMouseEvent>

#include <QDebug>
#include <QPushButton>
#include "ctime"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_HaveScor(false)
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
    //重新开始按钮
    start_Button=new QPushButton(this);
    start_Button->setStyleSheet
            ("QPushButton {border-image: url(://Images/replay.png);}");
    start_Button->setFixedSize(140,80);
    start_Button->move((WINDOWWHITE-start_Button->width())/2,WINDOWHEIGHT/2);
    connect(start_Button,SIGNAL(clicked()),this,SLOT(startGame()));
    start_Button->setVisible(false);

    m_Ground = new MoveGround(this);
    m_Ground->move(0,WINDOWHEIGHT - 60);

    //计分
    m_scor = new Scoring(this);
    m_scor->move((WINDOWWHITE - m_scor->width())/2,50);
    m_scor->setVisible(false);
    //开始窗体
    m_startView = new StartView(this);
    m_startView->setFixedSize(WINDOWWHITE,WINDOWHEIGHT);
    connect(m_startView,SIGNAL(clicked()),this,SLOT(startViewEnable()));
    connect(m_startView,SIGNAL(clicked()),this,SLOT(startGame()));
    m_startView->show();
}

void MainWindow::InitBird()
{
    m_Bird->move(QPoint(85,240));
    m_Bird->setRale(-50);
}

void MainWindow::initBirdFlyData()
{
    m_birdFlyData<<-3<<-3<<-3<<-3
                 <<-4<<-4<<-4<<-4<<-4
                 <<-3<<-3<<-3<<-3<<-3
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
    if(m_Bird->pos().y()+m_Bird->height()>=WINDOWHEIGHT - m_Ground->height())
    {         
        m_birdTimer->stop();
        gameOver();
    }
}

void MainWindow::startGame()
{
    if(!m_scor->isVisible()) {
        m_scor->setVisible(true);
    }
    InitBird();
    createPipes();
    m_Ground->play();
    start_Button->setVisible(false);
    int timeIter=8;
    m_birdTimer->start(timeIter);
    m_PiperTimer->start(timeIter);
}

void MainWindow::initPipes()
{
    m_PipeSpacing = 170;
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
        pipY = qrand()%180;
        m_Pipes[i]->move(pipeStartX+i*m_PipeSpacing,pipY-210);
    }
    m_lastPipeIndex = m_Pipes.count()-1;
}

void MainWindow::pipeManage()
{
    int pipY;
    for(int i =0; i<m_PipesCount;i++) {
        m_Pipes[i]->move(m_Pipes[i]->pos().x()-1,m_Pipes[i]->pos().y());
        if(m_Pipes[i]->pos().x()<-60) {
            pipY = qrand()%180;
            m_Pipes[i]->move(m_Pipes[m_lastPipeIndex]->pos().x()+m_PipeSpacing,pipY-210);
            m_lastPipeIndex=i;
            m_HaveScor = false;
            break;
        }
        //计分
        if(m_Pipes[i]->pos().x()<(m_Bird->pos().x()-m_Pipes[i]->width())&&!m_HaveScor) {
            m_scor->TotalScor();
            m_HaveScor = true;
             break;
        }
    }
}

void MainWindow::collisionDetect()
{
    int birdX = m_Bird->pos().x();
    for(int i=0;i<m_PipesCount;i++) {
        int pipeX=m_Pipes[i]->x();
        if(birdX+m_Bird->width()>=pipeX&&birdX<=pipeX+m_Pipes[i]->width()) {
            int pipHeihgt = m_Pipes[i]->getPipeHeight()+m_Pipes[i]->pos().y();
            if(m_Bird->pos().y()<=(pipHeihgt)||(m_Bird->pos().y()+m_Bird->height()/2)>=(pipHeihgt+ m_Pipes[i]->getPipeGap())){

                gameOver();
                break;
            }            
        }
    }
}

void MainWindow::gameOver()
{
    m_Ground->stop();
    m_PiperTimer->stop();
    start_Button->setVisible(true);
}

MainWindow::~MainWindow()
{
    qDeleteAll(m_Pipes);
    m_Pipes.clear();
    delete m_birdTimer;
    delete m_PiperTimer;
    delete m_scor;
    delete m_startView;
}

void MainWindow::startViewEnable()
{
    m_startView->close();
}

