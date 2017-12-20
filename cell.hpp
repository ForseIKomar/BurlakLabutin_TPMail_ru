#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <memory>

#include "board.hpp"
#include "figure.hpp"
#include "point.hpp"

class CCell{
private:
    SPoint point_; // координаты
    std::shared_ptr<CFigure> figure_; // фигура на клетке
    static std::shared_ptr<CBoard> game_field_;
public:
    CCell( SPoint point );
    CCell( std::shared_ptr<CFigure> &figure );

    static void SetBoard( std::shared_ptr<CBoard>& board );
    static std::shared_ptr<CBoard>& GetBoard();

    std::shared_ptr<CFigure>& GetFigure();

    bool IsEmpty();
    bool HasFigure();

    short GetRowNumber();
    short GetColumnNumber();
}; // клетка

#endif
