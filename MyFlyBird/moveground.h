#ifndef MOVEGROUND_H
#define MOVEGROUND_H

#include <QWidget>

class QTimer;
class MoveGround : public QWidget
{
    Q_OBJECT
public:
    explicit MoveGround(QWidget *parent = 0);
    ~MoveGround();
    void play();
    void stop();
signals:

public slots:
    void groundMove();
private:
    QTimer *m_timer;
    int m_bgX;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MOVEGROUND_H
