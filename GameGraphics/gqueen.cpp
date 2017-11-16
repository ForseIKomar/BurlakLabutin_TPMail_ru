#include "gqueen.h"

GQueen::GQueen(QColor color): GFigure()
{
    selfColor = color;
}

GQueen::~GQueen(){

}

void GQueen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(selfColor);
    painter->drawEllipse(0, 0, sc, sc);
    if (selfColor == Qt::black)
        painter->setPen(Qt::white);
    painter->drawEllipse((int)(sc * 0.2), (int)(sc * 0.2), (int)(sc * 0.6), (int)(sc * 0.6));
    if (selfColor == Qt::white)
        painter->setPen(Qt::black);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
