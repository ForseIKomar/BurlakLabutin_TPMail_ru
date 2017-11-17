#include "game.h"

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

Game::Game()
{

}

void Game::startNewGame(){
    generateNewGraphics();
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = 0;
    board[2][2] = 1;
    checkrs.push_back(Point(2, 2));
    addChecker(2, 2, Qt::black);
    canAttack = false;
    choosen = NULL;

}

Game::~Game(){
    whereCanMove.clear();
    whereCanAttack.clear();
    whatCanMove.clear();
}

void Game::touch(int x, int y){
    int c = -1;
    for (int i = 0; i < checkrs.size(); ++i)
        if (x == checkrs[i].x && y == checkrs[i].y){
            c = i;
        }
    char isChoosen = 'n';
    if (choosen != NULL){
            Move(*choosen, Point(x, y));
            delete choosen;
            choosen = NULL;
            isChoosen = 'y';
        }
        else{
            choosen = new Point(checkrs[c].x, checkrs[c].y);
    }
    logs->setText(QString::number(checkrs[0].x) + ' ' +
            QString::number(checkrs[0].y) + '  lel ' +
            QString::number(x) + ' ' + QString::number(y) + ' ' + isChoosen);
}

Vector_2 Game::CheckAttacks(Vector_3 vec, Point me){

}

Vector_2 Game::CheckMovies(Vector_3 vec, Point me){

}

Vector_2 Game::CheckCheckers(){

}

void Game::Move(Point x1, Point x2){
    MoveChecker(x1.x, x1.y, x2.x, x2.y);

    for (int i = 0; i < checkrs.size(); ++i)
        if (x1.x == checkrs[i].x && x1.y == checkrs[i].y){
            checkrs[i] = x2;
        }
}

void Game::Attack(Point x1, Point x2){

}

void Game::EndTurn(){

}
