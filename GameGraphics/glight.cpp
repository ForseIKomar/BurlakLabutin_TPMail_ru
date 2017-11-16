#include "glight.h"
#include <QPen>

GLight::GLight(): QGraphicsObject(){

}

GLight::~GLight(){

}

QRectF GLight::boundingRect() const{
    return QRectF(0, 0, sc, sc);
}

void GLight::setColor(QColor color){
    selfColor = color;
}

void GLight::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    /*
    QPen pen;
    pen.setColor(selfColor);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(1, 1, 49, 1);
    painter->drawLine(49, 1, 49, 49);
    painter->drawLine(49, 49, 1, 49);
    painter->drawLine(1, 49, 1, 1);*/

    painter->setBrush(selfColor);
    painter->drawEllipse((int)(sc * 0.4), (int)(sc * 0.4), (int)(sc * 0.2), (int)(sc * 0.2));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void GLight::setScaling(int scaling){
    sc = scaling;
}
