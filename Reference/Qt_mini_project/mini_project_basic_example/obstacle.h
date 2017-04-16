#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class OBSTACLE
        : public QWidget
{
    Q_OBJECT
public:
    explicit OBSTACLE(QWidget *parent = 0);
    ~OBSTACLE();

    int getH1();
    int getH2();
    int getGap();

private:
    int H1,H2;
    int Gap;

protected:
    void paintEvent(QPaintEvent *);


};

#endif // OBSTACLE_H
