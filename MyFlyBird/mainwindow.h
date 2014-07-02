#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
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
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
