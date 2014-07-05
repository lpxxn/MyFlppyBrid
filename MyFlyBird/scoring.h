#ifndef SCORING_H
#define SCORING_H

#include <QWidget>

class Scoring : public QWidget
{
    Q_OBJECT
public:
    explicit Scoring(QWidget *parent = 0);
    void TotalScor(int value =-1);
    int getScor();
signals:

public slots:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);

private:
    int m_TotalNum;
    enum{IMGPIXWIDTH=27};
    QStringList m_strList;
    QVector<QString> m_NumberImg;
};

#endif // SCORING_H
