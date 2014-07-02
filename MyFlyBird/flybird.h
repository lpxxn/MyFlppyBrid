#ifndef FLYBIRD_H
#define FLYBIRD_H

#include <QWidget>
#include <QTimer>


/*!
 * \brief The FlyBird class
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
    double rale;
    double x;
    int zt;
    double ztr;
    int co;
    QTimer * timer;
    QStringList src;
};

#endif // FLYBIRD_H
