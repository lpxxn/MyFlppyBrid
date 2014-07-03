#ifndef FLYBIRD_H
#define FLYBIRD_H

#include <QWidget>
#include <QTimer>


/*!
 * \brief The FlyBird class
 * 小鸟
 */
class FlyBird : public QWidget
{
    Q_OBJECT
public:
    explicit FlyBird(QWidget *parent = 0);
    ~FlyBird();

    /*!
     * \brief setRale
     * 设置窗体的旋转角度
     * \param rale
     */
    void setRale(int rale);

    /*!
     * \brief play
     * 开始
     */
    void play();

    /*!
     * \brief stop
     */
    void stop();
signals:

    /*!
     * \brief fly 转换信号
     *
     */
    void fly();

public slots:
    void updateRale();


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);

private:
    double rale;    //旋转角度
    QTimer * timer;
    QRect rect;
    QStringList m_birdImage;    //存放小鸟的图片
};

#endif // FLYBIRD_H
