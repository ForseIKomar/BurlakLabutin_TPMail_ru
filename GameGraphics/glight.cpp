#include "glight.h"
#include <QPen>

GLight::GLight(): QGraphicsObject(){

}

GLight::~GLight(){

}

QRectF GLight::boundingRect() const{
    return QRectF(0, 0, sc, sc);  // Показывает зону отрисовки
}

void GLight::setColor(QColor color){
    selfColor = color;
}

void GLight::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(selfColor);
    painter->drawEllipse((int)(sc * 0.4), (int)(sc * 0.4), (int)(sc * 0.2), (int)(sc * 0.2));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void GLight::setScaling(int scaling){
    sc = scaling;
}
