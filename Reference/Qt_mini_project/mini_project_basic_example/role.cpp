#include "role.h"

ROLE::ROLE(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(35,35);
    src=":/Image/bird1.png";
}

ROLE::~ROLE()
{

}

void ROLE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(src);
    painter.drawPixmap(0,0,35,35,pix);
}

