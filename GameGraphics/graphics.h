#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QVector>

#include "gchecker.h"
#include "gqueen.h"
#include "glight.h"

class Graphics: public QGraphicsScene
{

    Q_OBJECT

public:
    explicit Graphics(QObject *parent = 0);
    ~Graphics();

private:
    QVector <GFigure *> Checkers;
    QVector <GLight *> Lighting;

    GFigure *Choosen;

    QLabel *logs;
    int sc; // scaling - shows size of one cell

public:
    void setLabel(QLabel *label);
    void setScaling(int scl);
    void generateNewGraphics();

private:
    void addChecker(int x, int y, QColor color);
    void addLighting(int x, int y, QColor color);

    // Для передачи передвижения.
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // GRAPHICS_H
