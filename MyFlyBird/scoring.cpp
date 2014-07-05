#include <QPainter>
#include <QPixmap>
#include "scoring.h"
#include <QDebug>

Scoring::Scoring(QWidget *parent) :
    QWidget(parent),m_TotalNum(0)
{    
    this->setGeometry(0,0,IMGPIXWIDTH*4,36);
    for(int i=0;i<10;i++)
    {
        m_NumberImg<<QString("://Images/scoreNumber/%1.png").arg(i);
    }
}

void Scoring::TotalScor(int value)
{
    if(value==-1) {
        m_TotalNum++;
    }
    else {
        m_TotalNum = value;
    }
    m_strList.clear();
    QString str=QString::number(m_TotalNum);

    if(m_TotalNum>=10) {
        for (int i= 0; i <= str.size()-1;i++) {
            m_strList<<str.at(i);
        }
    }
    else {
        m_strList<<str;
    }
    update();
}

int Scoring::getScor()
{
    return m_TotalNum;
}


void Scoring::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    painter.setWindow(0,0,IMGPIXWIDTH*4,36);
    if(m_strList.count()==0) {
        pix.load(m_NumberImg.at(0));
        painter.drawPixmap(IMGPIXWIDTH,0,pix);
    }
    else if(m_strList.count()==1) {
        pix.load(m_NumberImg.at(m_strList.at(0).toInt()));
        painter.drawPixmap(IMGPIXWIDTH,0,pix);
    }
    else if(m_strList.count()>1) {
        for(int i=0;i<m_strList.count();i++) {
            pix.load(m_NumberImg.at(m_strList.at(i).toInt()));
            painter.drawPixmap(i*IMGPIXWIDTH,0,IMGPIXWIDTH,36,pix);
        }
    }
}
