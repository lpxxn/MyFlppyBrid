#include <QPainter>
#include <QPixmap>

#include "blockpipe.h"

BlockPipe::BlockPipe(QWidget *parent) :
    QWidget(parent)
{
    setPipeGap(135);
}

void BlockPipe::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing,true);
    QPixmap pix;
    pix.load("://Images/pipe1.png");
    painter.drawPixmap(0,0,PIPEWIDTH,PIPEHEIGHT,pix);
    pix.load("://Images/pipe2.png");
    painter.drawPixmap(0,PIPEHEIGHT+getPipeGap(),PIPEWIDTH,PIPEHEIGHT,pix);
}

int BlockPipe::getPipeGap() const
{
    return m_PipeGap;
}

void BlockPipe::setPipeGap(int PipeGap)
{
    this->setFixedSize(PIPEWIDTH,PipeGap+600);
    m_PipeGap = PipeGap;
    update();
}

int BlockPipe::getPipeHeight()
{
    return PIPEHEIGHT;
}




