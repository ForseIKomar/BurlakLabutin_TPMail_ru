#include "board.hpp"
#include "point.hpp"

const short kBoardSideSize = 8;


CBoard::CBoard()
{
    // координаты клеток: нумеруются с 0 !!!
    short i_row = 0;  // номер строки
    short i_column = 0; // номер столбца

    // создание доски с пустыми клетками
    for( auto &row: game_field_ ){
        for( auto &cell: row ){
            cell( new CCell( SPoint( i_column, i_row ) ) );
            ++i_column;
        }
        ++i_row;
    }
}


std::shared_ptr<CCell>& CBoard::GetCell( short i_row, short i_column )
{
	if( i_row < 0 ){
		i_row = 0;
	}
	if( i_row >= kBoardSideSize ){
		i_row = kBoardSideSize - 1;
	}

	if( i_column < 0 ){
		i_column = 0;
	}
	if( i_column >= kBoardSideSize ){
		i_column = kBoardSideSize - 1;
	}

	return game_field_[i_row][i_column];
}


void CBoard::SetCheckers()
{
    short cell_x[] = { 1, 0 }; // номера клеток по столбцам с фигурами
    short cells_row_count = ( kBoardSideSize - 2 ) / 2; // количество строк с фигурами одного цвета
    // расстановка чёрных шашек
    for( short i_row = 0; i_row < cells_row_count; ++i_row ){
        for( short i_column = cell_x[ i_row % 2 ]; i_column < kBoardSideSize; i_column += 2 ){
            (game_field_[i_row][i_column])( new CChecker( 'B', game_field_[i_row][i_column] ) );
        }
    }
    // расстановка белых шашек
    for( short i_row = cells_row_count + 2; i_row < kBoardSideSize; ++i_row ){
        for( short i_column = cell_x[i_row%2]; i_column < kBoardSideSize; i_column += 2 ){
            (game_field_[i_row][i_column])( new CChecker( 'W', game_field_[i_row][i_column] ) );
        }
    }
}


void CBoard::WhoCanMove( std::vector<std::shared_ptr<CFigure>> &potential_figures, char color )
{
	std::shared_ptr<CCell> cell = nullptr;
	std::shared_ptr<CFigure> figure = nullptr;
	
	for( short i_row = 0; i_row < kBoardSideSize; ++i_row ){
		for( short i_column = 0; i_column < kBoardSideSize; ++i_column ){
			if( ( cell = game_field_[i_row][i_column] ) -> HasFigure() && 
				color == ( figure = cell -> GetFigure() ) -> GetColor() &&
				figure -> CanMove() )
			{
				potential_figures.push_back( figure );
			}
		}
	}
}


void CBoard::WhoCanAttack( std::vector<std::shared_ptr<CFigure>> &potential_figures, char color )
{
	std::shared_ptr<CCell> cell = nullptr;
	std::shared_ptr<CFigure> figure = nullptr;
	
	for( short i_row = 0; i_row < kBoardSideSize; ++i_row ){
		for( short i_column = 0; i_column < kBoardSideSize; ++i_column ){
			if( ( cell = game_field_[i_row][i_column] ) -> HasFigure() &&
				color == ( figure = cell -> GetFigure() ) -> GetColor() &&
				figure -> CanAttack() )
			{
				potential_figures.push_back( figure );
			}
		}
	}
}


void CBoard::Move( std::shared_ptr<CFigure> &moving_figure, std::shared_ptr<CCell> &new_cell )
{
	new_cell -> GetFigure() = moving_figure;
	moving_figure = nullptr;
}
