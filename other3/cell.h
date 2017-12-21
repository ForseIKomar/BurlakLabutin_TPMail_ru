#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <memory>

#include "board.hpp"
#include "figure.hpp"
#include "point.hpp"

class CBoard;

class CCell{
private:
    SPoint point_; // координаты
    std::shared_ptr<CFigure> figure_; // фигура на клетке
    //static std::shared_ptr<CBoard> game_field_;
public:
    CCell( SPoint point );
    void SetFigure( std::shared_ptr<CFigure> figure );

    //void SetBoard( std::shared_ptr<CBoard>& board );
    //std::shared_ptr<CBoard>& GetBoard();

    std::shared_ptr<CFigure>& GetFigure();

    bool IsEmpty();
    bool HasFigure();

    short GetRowNumber();
    short GetColumnNumber();
}; // клетка

//std::shared_ptr<CBoard> CCell::game_field_;
#endif
