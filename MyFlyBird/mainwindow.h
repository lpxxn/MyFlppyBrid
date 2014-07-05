#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "flybird.h"
#include "blockpipe.h"
#include "moveground.h"
#include "scoring.h"
#include "startview.h"
#include "gameoverview.h"

class QPushButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:

    /*!
     * \brief startViewEnable
     * 开始窗体
     */
    void startViewEnable();
    /*!
     * \brief birdFlppy
     * 小鸟飞行
     */
    void birdFlppy();

    /*!
     * \brief startGame
     * 开始游戏
     */
    void startGame();

    /*!
     * \brief pipeManage
     * 管理管子
     */
    void pipeManage();

    /*!
     * \brief collisionDetect
     * 碰撞测试
     */
    void collisionDetect();

    /*!
     * \brief overViewShow
     */
    void overViewShow();
private:
    StartView * m_startView;

    FlyBird *m_Bird;
    QTimer * m_birdTimer;   //控制小鸟飞行
    enum e_WinSize{WINDOWWHITE = 360,WINDOWHEIGHT = 500};
    double m_birdHeight;
    void InitBird();
    QVector<double> m_birdFlyData;
    QVector<double>::iterator m_birdFlyIterator;
    QVector<double>::iterator m_birdFlyIteratorEnd;
    /*!
     * \brief initBirdFlyData
     * 点击小鸟向上飞是有一个加向上再向下的一个过程，这是初始化这个过程需要的数据
     */
    void initBirdFlyData();

    //管道
    QVector<BlockPipe *> m_Pipes;
    int m_PipeSpacing;
    const int m_PipesCount = 3;
    QTimer * m_PiperTimer;  //控制管道
    int m_lastPipeIndex;
    void initPipes();
    /*!
     * \brief createPipes
     * 创建管道
     */
    void createPipes();

    /*!
     * \brief gameOver
     * 游戏结束
     */
    void gameOver();

    //滚动的绿地
    MoveGround * m_Ground;

    //计分
    Scoring * m_scor;
    bool m_HaveScor;
    QTimer * m_overViewTimer;
    GameOverView * m_overView;
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
