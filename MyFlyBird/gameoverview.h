#ifndef GAMEOVERVIEW_H
#define GAMEOVERVIEW_H

#include <QWidget>
#include <QPushButton>

#include "scoring.h"
class GameOverView : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverView(QWidget *parent = 0);
    void SetScor(int scor);
signals:
    void clicked();
public slots:

private:
    QPushButton * m_BtnStar;
    Scoring * m_TotalNum;
    Scoring * m_TopNum;
    enum {hehe,good,best} socrState;
    /*!
     * \brief SaveScore
     * 保存最高分
     * \param score
     * 分数
     */
    void SaveScore(int score);

    /*!
     * \brief GetScore
     * 得到最高分
     * \return
     */
    int GetScore();
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // GAMEOVERVIEW_H
