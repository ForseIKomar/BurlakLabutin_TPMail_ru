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
    QVector <GFigure *> Checkers;   // Вектор фигур на доске для их отрисовки
    QVector <GLight *> Lighting;    // То же самое для подсветки

    GFigure *Choosen;               // Выбранная шашка (Потом уйдет в логику)

    int sc;

public:
    void setLabel(QLabel *label);   // Установка label для вывода логов
    void setScaling(int scl);       // Установка масштабирования
    void generateNewGraphics();     // Очистка доски и построение игры заного (Позже будет не нужно)

protected:
    void addChecker(int x, int y, QColor color);  // Добавление Шашки на клетку
    void addLighting(int x, int y, QColor color);  // Добавление подсветки на клетку

    void MoveChecker(int x1, int y1, int x2, int y2);

    virtual void touch(int x, int y) = 0;
    // Для передачи передвижения.
    void mousePressEvent(QGraphicsSceneMouseEvent * event);


    QLabel *logs;

};

#endif // GRAPHICS_H

/*
    Этот класс создан для отображения всей игровой графики
 */
