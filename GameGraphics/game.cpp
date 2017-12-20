#include "game.h"

Game::Game()
{

}

void Game::startNewGame(){
    generateNewGraphics();
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = 0;

    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j < 4; ++j){
            board[j * 2 + (i + 1) % 2][i] = 1;
            checkrs.push_back(SPoint(j * 2 + (i + 1) % 2, i));
            addChecker(j * 2 + (i + 1) % 2, i, Qt::black);
        }

    for (int i = 7; i >= 5; i--)
        for (int j = 0; j < 4; ++j){
            board[j * 2 + (i + 1) % 2][i] = 3;
            checkrs.push_back(SPoint(j * 2 + (i + 1) % 2, i));
            addChecker(j * 2 + (i + 1) % 2, i, Qt::white);
        }
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
            Attack(*choosen, SPoint(x, y));
            delete choosen;
            choosen = NULL;
            isChoosen = 'y';
        }
        else{
            if (c != -1){
                choosen = new SPoint(checkrs[c].x, checkrs[c].y);
            }
    }
    /*
    logs->setText(QString::number(2) + ' ' +
            QString::number(5) + "  lel " +
            QString::number(x) + ' ' + QString::number(y) + ' ' + isChoosen);*/
}

Vector_2 test;

Vector_2 Game::CheckAttacks(Vector_3 vec, SPoint me){
    return test;
}

Vector_2 Game::CheckMovies(Vector_3 vec, SPoint me){
    return test;
}

Vector_2 Game::CheckCheckers(){
    return test;
}

void Game::Move(SPoint x1, SPoint x2){
    MoveChecker(x1, x2);
    int t = board[x1.x][x1.y];
    board[x1.x][x1.y] = 0;
    board[x2.x][x2.y] = t;
    for (int i = 0; i < checkrs.size(); ++i)
        if (x1.x == checkrs[i].x && x1.y == checkrs[i].y){
            checkrs[i] = x2;
        }
}

void Game::Attack(SPoint x1, SPoint x2){
    Move(x1, x2);
    logs->setText("lol" + QString::number(x1.x));
    if (abs(x2.x - x1.x) == 2 && abs(x2.y - x1.y) == 2){
        int dx = ((x2.x - x1.x) >= 0) ? 1 : -1;
        int dy = ((x2.y - x1.y) >= 0) ? 1 : -1;
        logs->setText(QString::number(dx) + ' '
                      + QString::number(dy));
        if (board[x1.x + dx][x1.y + dy] != 0){
            deleteGFigure(x1.x + dx, x1.y + dy);

            for (int i = 0; i < checkrs.size(); ++i)
                if ((x1.x + dx) == checkrs[i].x && (x1.y + dy) == checkrs[i].y){
                    for (int j = i; j < checkrs.size() - 1; ++j)
                        checkrs[j] = checkrs[j + 1];
                    checkrs.pop_back();
                }
        }
    }
}

void Game::EndTurn(){

}
