#include "checker.hpp"
#include "cell.h"

CChecker::CChecker( char checker_color, std::shared_ptr<CCell> &checker_cell )
    : CFigure( checker_color, checker_cell )
{}


void CChecker::WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	short i_row = figure_cell_ -> GetRowNumber();
	short i_column = figure_cell_ -> GetColumnNumber();
	// номер строки новой клетки
	short i_new_row = ( figure_color_ == 'W' ) ? i_row - 1 : i_row + 1;
	// изменение номера столбца клетки
	short add[] = { -1, 1 };

	std::shared_ptr<CCell> new_cell = nullptr;
	for( short j = 0; j < 2; ++j ){
		new_cell = figure_cell_ -> GetBoard() -> GetCell( i_new_row, i_column + add[j] );
		if( new_cell != nullptr && new_cell -> IsEmpty() ){
			potential_cells.push_back( new_cell );
		}
	}
}


void CChecker::WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	short i_row  = figure_cell_ -> GetRowNumber();
	short i_column = figure_cell_ -> GetColumnNumber();
	
	// номер строки с фигурой противника
	short i_enemy_row = ( figure_color_ == 'W' ) ? i_row - 1 : i_row + 1;
	// номер строки с клеткой для перехода
	short i_move_row  = ( figure_color_ == 'W' ) ? i_enemy_row - 1 : i_enemy_row + 1;
	// изменение номера столбца клетки с фигурой противника и клетки для хода 
    short add[2][2] = { { -1, -2 }, // влево
					  {  1,  2 } // вправо
					};
	
	std::shared_ptr<CCell> enemy_cell = nullptr;
	std::shared_ptr<CCell> move_cell  = nullptr;
	for( short j = 0; j < 2; ++j ){
		enemy_cell = figure_cell_ -> GetBoard() -> GetCell( i_enemy_row, i_column + add[j][0] );
		move_cell  = figure_cell_ -> GetBoard() -> GetCell( i_move_row,  i_column + add[j][1] );
		if( move_cell != nullptr && move_cell -> IsEmpty() && enemy_cell -> HasFigure() &&
		    figure_color_ != enemy_cell -> GetFigure() -> GetColor() )
		{
			potential_cells.push_back( move_cell );
		}
	}
}

/*
void CChecker::Move( short i_row, short i_column )
{
	std::shared_ptr<CCell> new_cell = CCell::GetBoard() -> GetCell( i_row, i_column );
	(new_cell -> GetFigure())( new CChecker( figure_cell_, new_cell ) );
	//std::shared_ptr<CCell> this_cell = figure_cell_;
	//figure_cell_ = new_cell;
	delete *( figure_cell_ -> GetFigure() ); 
}
*/

/*CChecker& CChecker::operator= ( CChecker &current_checker )
{
    figure_color_ = current_checker.GetColor();
    figure_cell_ = current_checker.GetCell();
}*/

/*
CFigure::CFigure( char figure_color, std::shared_ptr<CCell>& figure_cell )
    : figure_color_( figure_color ), figure_cell_( figure_cell )
{}


CFigure::~CFigure()
{
    figure_cell_ = nullptr;
}


char CFigure::GetColor()
{
    return figure_color_;
}


std::shared_ptr<CCell>& CFigure::GetCell()
{
    return figure_cell_;
}


bool CFigure::CanMove()
{
    std::vector<std::shared_ptr<CCell>> potential_cells;
    WhereCanMove( potential_cells );
    if( potential_cells.size() != 0 ){
        return true;
    } else{
        return false;
    }
}


bool CFigure::CanAttack()
{
    std::vector<std::shared_ptr<CCell>> potential_cells;
    WhereCanAttack( potential_cells );
    if( potential_cells.size() != 0 ){
        return true;
    } else{
        return false;
    }
}
*/
