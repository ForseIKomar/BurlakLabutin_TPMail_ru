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
}

void Graphics::addChecker(int x, int y, QColor color){

    GChecker *newitem = new GChecker(color);
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
    QString c;
    if (Choosen == NULL)
        c = "no choosen";
    else
        c = "choosen at " + QString::number(Choosen->pos().x()) + ' ' +
                QString::number(Choosen->pos().y());
    logs->setText(
                QString::number(event->scenePos().x())
                + ' ' +
                QString::number(event->scenePos().y()) + ' ' + c
                );

    if (Choosen == NULL){
        for (int i = 0; i < Checkers.size(); ++i){
            if ( (int)(event->scenePos().x() / sc) == (int)(Checkers[i]->pos().x() / sc) &&
                 (int)(event->scenePos().y() / sc) == (int)(Checkers[i]->pos().y() / sc)){
                Choosen = Checkers[i];
            }
        }
    }
    else{
        Choosen->setPos((int)(event->scenePos().x() / sc) * sc,
                (int)(event->scenePos().y() / sc) * sc);
        Choosen = NULL;
    }
}
