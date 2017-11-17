#include "gchecker.h"

GChecker::GChecker(QColor color): GFigure()
{
    selfColor = color;
}

GChecker::~GChecker(){

}

void GChecker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(selfColor);
    painter->drawEllipse(0, 0, sc, sc);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
