#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>

#include "flybird.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

    void BirdFlppy();
private:
    FlyBird *m_Bird;
    QTimer * m_birdTimer;
    enum e_WinSize{WINDOWWHITE = 360,WINDOWHEIGHT = 500};
    double m_birdHeight;

    QList<double> m_birdFlyData;
    QList<double>::iterator m_birdFlyIterator;
    /*!
     * \brief initBirdFlyData
     * 点击小鸟向上飞是有一个加向上再向下的一个过程，这是初始化这个过程需要的数据
     */
    void initBirdFlyData();
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
