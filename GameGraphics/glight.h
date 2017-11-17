#ifndef GLIGHT_H
#define GLIGHT_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>

class GLight: public QGraphicsObject
{

    Q_OBJECT

public:
    explicit GLight();
    ~GLight();
    void setColor(QColor color);
    void setScaling(int scaling);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QColor selfColor;
    int sc;
};

#endif // GLIGHT_H
