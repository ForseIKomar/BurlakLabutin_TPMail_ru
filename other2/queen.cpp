#include "queen.hpp"
#include "cell.h"

CQueen::CQueen( char queen_color, std::shared_ptr<CCell> &queen_cell )
	: CFigure( queen_color, queen_cell) 
{}


void CQueen::WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	int i_row = figure_cell_ -> GetRowNumber();
	int i_column = figure_cell_ -> GetColumnNumber();

	std::shared_ptr<CCell> new_cell = nullptr;
	// номера строк и столбцов клеток, возможных для хода
	int indices[][2] = { { i_row - 1, i_column - 1 }, // левый верх
						 { i_row - 1, i_column + 1 }, // правый верх
						 { i_row + 1, i_column - 1 }, // левый низ
						 { i_row + 1, i_column + 1 } // правый низ
					   };
	// изменение номеров строк и столбцов клеток для хода
	int add[][2] = { { -1, -1 }, // левый верх
					 { -1,  1 }, // правый верх
					 {  1, -1 }, // левый низ
					 {  1,  1 } // правый низ
				   };

	for( short j = 0; j < 4; ++j ){
		for( short i_new_row = indices[j][0], i_new_column = indices[j][1];
		     ( new_cell = figure_cell_ -> GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
		     new_cell -> IsEmpty();
		     i_new_row += add[j][0], i_new_column += add[j][1] )
		{
			potential_cells.push_back( new_cell );
		}
	}
}


void CQueen::WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	int i_row  = figure_cell_ -> GetRowNumber();
	int i_column = figure_cell_ -> GetColumnNumber();
	// номера строк и столбцов клеток, возможных для хода
	int indices[][2] = { { i_row - 1, i_column - 1 }, // левый верх
						 { i_row - 1, i_column + 1 }, // правый верх
						 { i_row + 1, i_column - 1 }, // левый низ
						 { i_row + 1, i_column + 1 } // правый низ
						};
	// изменение номеров строк и столбцов клеток для хода
	int add[][2] = { { -1, -1 }, // левый верх
					 { -1,  1 }, // правый верх
					 {  1, -1 }, // левый низ
					 {  1,  1 } // правый низ
				   };

	std::shared_ptr<CCell> new_cell = nullptr;
	
	for( short j = 0; j < 4; ++j ){
		// поиск вдоль диагонали первой клетки с фигурой
		short i_new_row = indices[j][0];
		short i_new_column = indices[j][1];
		for( ; ( new_cell = figure_cell_ -> GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
			   new_cell -> IsEmpty();
			   i_new_row += add[j][0], i_new_column += add[j][1]
		);
		// клетка - в пределах доски и фигура - противника ?
		if( new_cell != nullptr && figure_color_ != new_cell -> GetFigure() ->GetColor() ){
			i_new_row += add[j][0];
			i_new_column += add[j][1];
			// отмечаем все возможные, т.е. пустые, для хода дамки клетки после атаки фигуры противника
			while( (new_cell = figure_cell_ -> GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
				   new_cell -> IsEmpty() )
			{
				potential_cells.push_back( new_cell );
			}
		}
	}
}
