#ifndef BLOCKPIPE_H
#define BLOCKPIPE_H

#include <QWidget>

/*!
 * \brief The BlockPipe class
 * 管子
 */
class BlockPipe : public QWidget
{
    Q_OBJECT
public:
    explicit BlockPipe(QWidget *parent = 0);

    int getPipeGap() const;
    void setPipeGap(int pipeGap);
    int getPipeHeight();

signals:

public slots:

private:
    /*!
     * \brief m_PipeGap
     * 管子之间的空隙
     */
    int m_PipeGap;
    enum m_PipeSize{PIPEWIDTH=65,PIPEHEIGHT=300};
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // BLOCKPIPE_H
