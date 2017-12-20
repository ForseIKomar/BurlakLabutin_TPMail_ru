#include "graphics.h"

Graphics::Graphics(QObject *parent) : QGraphicsScene(parent){

}

Graphics::~Graphics(){

}

void Graphics::setLabel(QLabel *label){
    logs = label;
}

void Graphics::setScaling(int scl){
    sc = scl;
}

void Graphics::generateNewGraphics(){
    clear();
    Checkers.clear();
    Lighting.clear();
    Choosen = NULL;
    QPen pen;
    pen.setColor(Qt::black);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j){
            if ((i + j) % 2 == 0)
                addRect(i * sc, j * sc, sc, sc, pen, Qt::white);
            else
                addRect(i * sc, j * sc, sc, sc, pen, Qt::gray);
        }

    /*
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j < 4; ++j){
            addChecker(j * 2 + (i + 1) % 2, i, Qt::black);
            if (i == 2)
                addLighting(j * 2 + (i + 1) % 2, i, Qt::yellow);
        }

    addLighting(0, 3, Qt::green);
    addLighting(2, 3, Qt::green);
    addLighting(5, 4, Qt::red);

    for (int i = 7; i >= 5; i--)
        for (int j = 0; j < 4; ++j)
            addChecker(j * 2 + (i + 1) % 2, i, Qt::white);
    */
}

void Graphics::addChecker(int x, int y, QColor color){

    GChecker *newitem = new GChecker(color);
    newitem->setPos(x * sc, y * sc);
    newitem->setScaling(sc);

    Checkers.push_back(newitem);
    addItem(newitem);
}

void Graphics::addQueen(int x, int y, QColor color){
    GQueen *newitem = new GQueen(color);
    newitem->setPos(x * sc, y * sc);
    newitem->setScaling(sc);

    Checkers.push_back(newitem);
    addItem(newitem);
}

void Graphics::addLighting(int x, int y, QColor color){

    GLight *newitem = new GLight();
    newitem->setColor(color);
    newitem->setPos(x * sc, y * sc);
    newitem->setScaling(sc);

    Lighting.push_back(newitem);
    addItem(newitem);
}

void Graphics::mousePressEvent(QGraphicsSceneMouseEvent *event){
    touch((int)(event->scenePos().x() / sc), (int)(event->scenePos().y() / sc));
}

void Graphics::MoveChecker(SPoint x1, SPoint x2){
    for (int i = 0; i < Checkers.size(); ++i){
        if (x1.x == (int)(Checkers[i]->pos().x()  / sc) &&
                x1.y == (int)(Checkers[i]->pos().y()  / sc))
            Checkers[i]->setPos(x2.x * sc, x2.y * sc);
    }
}

void Graphics::deleteGFigure(int x, int y){
    int i = 0;
    int c = 0;
    while (i < Checkers.size()){
        if (x == (int)(Checkers[i]->pos().x()  / sc) &&
                y == (int)(Checkers[i]->pos().y()  / sc))
        {
            removeItem(Checkers[i]);
            Checkers.remove(i);
        }
        i++;
    }

}
