#ifndef GQUEEN_H
#define GQUEEN_H

#include <QObject>
#include <QColor>

#include "gfigure.h"

class GQueen: public GFigure
{

    Q_OBJECT

public:
    explicit GQueen(QColor color);
    ~GQueen();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GQUEEN_H
