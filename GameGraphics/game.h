#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include <vector>

struct Point{
    Point(int x, int y);
    int x, y;
};

typedef std::vector<Point> Vector_2;
typedef std::vector<Vector_2> Vector_3;


class Game: public Graphics
{
public:
    Game();
    ~Game();
private:
    int board[8][8];
    Vector_2 checkrs;
    int turn;
    Vector_2 whereCanMove;
    Vector_2 whatCanMove;
    Vector_2 whereCanAttack;
    bool canAttack;
    Point *choosen;

public:
    void touch(int x, int y);
    void startNewGame();
private:
    Vector_2 CheckMovies(Vector_3 vec, Point me);
    Vector_2 CheckAttacks(Vector_3 vec, Point me);
    Vector_2 CheckCheckers();
    void Move(Point x1, Point x2);
    void Attack(Point x1, Point x2);
    void EndTurn();
};

#endif // GAME_H
