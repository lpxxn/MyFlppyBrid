#include "gameoverview.h"
#include <QPainter>
#include <QPixmap>
#include <QFile>
#include <QDataStream>
GameOverView::GameOverView(QWidget *parent) :
    QWidget(parent)
{
    m_BtnStar =new QPushButton(this);
    m_BtnStar->setStyleSheet
            ("QPushButton {border-image: url(://Images/replay.png);}");
    m_BtnStar->setFixedSize(140,80);
    connect(m_BtnStar,SIGNAL(clicked()),this,SIGNAL(clicked()));



    m_BtnStar->move(110,340);
    m_TotalNum = new Scoring(this);

    m_TotalNum->setFixedSize(70,20);
    m_TotalNum->move(250,205);
    m_TopNum =  new Scoring(this);
    m_TopNum->setFixedSize(70,20);
    m_TopNum->move(250,265);

}

void GameOverView::SetScor(int scor)
{
    int old= GetScore();

    m_TotalNum->TotalScor(scor);
    if(scor==0) {
        socrState =hehe;
        m_TopNum->TotalScor(old);
    }
    if(old<scor) {
        socrState=best;
        SaveScore(scor);
        m_TopNum->TotalScor(scor);
    }
    else {
        socrState=good;
        m_TopNum->TotalScor(old);
    }
}

void GameOverView::SaveScore(int score)
{
    QFile file("scor.fly");
    file.open(QIODevice::WriteOnly);
    QDataStream o(&file);
    o<<score;
}

int GameOverView::GetScore()
{
    QFile file("scor.fly");
    file.open(QIODevice::ReadOnly);
    QDataStream o(&file);
    int s;
    o>>s;
    return s;
}

void GameOverView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;

    pix.load("://Images/gameover.png");
    painter.drawPixmap(50,80,pix);
    pix.load("://Images/scoreboard.png");
    painter.drawPixmap(35,160,pix);

    switch(socrState) {
    case hehe:
        pix.load("://Images/medal2.png");
        break;
    case good:
        pix.load("://Images/medal1.png");
        break;
    case best:
        pix.load("://Images/medal0.png");
        break;
    }
    painter.drawPixmap(68,220,pix);

}
