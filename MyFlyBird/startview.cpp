#include "startview.h"
#include <QPainter>
#include <QPixmap>
StartView::StartView(QWidget *parent) :
    QWidget(parent)
{
}

void StartView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://Images/ready.png");
    painter.drawPixmap(0,0,pix);
}

void StartView::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}
