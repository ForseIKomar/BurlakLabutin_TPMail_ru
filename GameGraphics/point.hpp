#ifndef __POINT_HPP__
#define __POINT_HPP__

typedef struct Point{
    short x; // номер столбца
    short y; // номер строки
    Point( short x1 = 0, short y1 = 0 )
        : x( x1 ), y( y1 )
    {}
} SPoint; // координаты клетки на доске

#endif
