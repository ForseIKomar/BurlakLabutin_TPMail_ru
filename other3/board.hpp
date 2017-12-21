#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <array>
#include <memory>
#include <vector>

#include "cell.h"
#include "figure.hpp"
#include "checker.hpp"

const short kBoardSideSize = 8; // размер доски

class CFigure;

class CCell;

class CBoard{
private:
    std::array<std::array<std::shared_ptr<CCell>, kBoardSideSize>, kBoardSideSize> game_field_;
public:
    CBoard();

    void SetCheckers(); // расстановка шашек на доске
    std::shared_ptr<CCell>& GetCell( short i_row, short i_column );

    void WhoCanMove(   std::vector<std::shared_ptr<CFigure>> &potential_figures, char color );
    void WhoCanAttack( std::vector<std::shared_ptr<CFigure>> &potential_figures, char color );

    void Move( std::shared_ptr<CFigure> &moving_figure, std::shared_ptr<CCell> &new_cell );
	//void Attack( std::shared_ptr<CFigure> &attacking_figure, 
}; // игровое поле

#endif
