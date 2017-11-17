#include "gfigure.h"

GFigure::GFigure(): QGraphicsObject(){

}

GFigure::~GFigure(){

}

QRectF GFigure::boundingRect() const{
    return QRectF(0, 0, sc, sc);  // Показывает зону отрисовки
}

void GFigure::setColor(QColor color){
    selfColor = color;
}

void GFigure::setScaling(int scaling){
    sc = scaling;
}
