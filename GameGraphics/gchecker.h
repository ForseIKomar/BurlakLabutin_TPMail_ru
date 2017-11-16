#ifndef GCHECKER_H
#define GCHECKER_H

#include <QObject>
#include <QColor>

#include "gfigure.h"

class GChecker: public GFigure
{

    Q_OBJECT

public:
    explicit GChecker(QColor color);
    ~GChecker();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GCHECKER_H
