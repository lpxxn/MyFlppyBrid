#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>

class StartView : public QWidget
{
    Q_OBJECT
public:
    explicit StartView(QWidget *parent = 0);

signals:
    void clicked();
public slots:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
};

#endif // STARTVIEW_H
