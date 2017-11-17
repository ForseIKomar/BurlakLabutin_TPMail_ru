#ifndef GFIGURE_H
#define GFIGURE_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>

class GFigure: public QGraphicsObject
{

    Q_OBJECT

public:
    explicit GFigure();
    ~GFigure();
    void setColor(QColor color);
    void setScaling(int scaling);

private:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

protected:
    QColor selfColor;
    int sc;
};

#endif // GFIGURE_H
