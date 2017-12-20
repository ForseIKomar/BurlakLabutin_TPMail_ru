#include <array>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

const static short kBoardSideSize = 8; // размер доски

typedef struct Point{
    short x; // номер столбца
    short y; // номер строки
    Point( short x1 = 0, short y1 = 0 )
        : x( x1 ), y( y1 )
        {}
} SPoint; // координаты клетки на доске


class CCell{
public:
	CCell( SPoint );
};
class CFigure;


class CBoard{
private:
    std::array<std::array<std::shared_ptr<CCell>, kBoardSideSize>, kBoardSideSize> game_field_;
public:
    CBoard();

    void SetCheckers(); // расстановка шашек на доске
    std::shared_ptr<CCell>& GetCell( short i_row, short i_column ); 
	void WhoCanAttack( std::vector<std::shared_ptr<CFigure>> &potential_figures, char color );
	void WhoCanMove(   std::vector<std::shared_ptr<CFigure>> &potential_figures, char color );
}; // игровое поле

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


class CCell{
private:
    SPoint point_; // координаты
    std::shared_ptr<CFigure> figure_; // фигура на клетке
    static std::shared_ptr<CBoard> game_field_;
public:
    CCell( SPoint point )
        : point_( point ), figure_( nullptr )
    {}
    CCell( std::shared_ptr<CFigure> &figure )
        : figure_( figure )
    {}

    static void SetBoard( std::shared_ptr<CBoard>& board )
        : game_field( board )
    {}
    static std::shared_ptr<CBoard>& GetBoard()
    {
        return game_field_;
    }

    bool IsEmpty()
    {
        return ( figure_ == nullptr ) ? true : false;
    }
    bool HasFigure()
    {
        return ( figure_ != nullptr ) ? true : false;
    }
    short GetRowNumber()
    {
        return point_.y;
    }
    short GetColumnNumber()
    {
        return point_.x;
    }

    std::shared_ptr<CFigure>& GetFigure();
}; // клетка


std::shared_ptr<CFigure>& CCell::GetFigure()
{
    return figure_;
}

class CFigure{
private:
	char figure_color_;
	std::shared_ptr<CCell> figure_cell_; // клетка, на которой расположена фигура
public:
	CFigure( char figure_color, std::shared_ptr<CCell>& figure_cell )
		: figure_color_( figure_color ), figure_cell_( figure_cell )
	{}

	char GetColor()
	{
		return figure_color_;
	}
	std::shared_ptr<CCell>& GetCell()
	{
		return figure_cell_;
	}

	virtual void WhereCanMove(   std::vector<std::shared_ptr<CCell>> &potential_cells ) = 0;
	virtual void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells ) = 0;
	bool CanMove();
	bool CanAttack();
	void Move(   short i_row, short i_column ) = 0; // ход в данную клетку - не реализован
	void Attack( short i_row, short i_column ) = 0; // атаковать и перейти в данную клетку - не реализован
};

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
	if( potential.cells.size() != 0 ){
		return true;
	} else{
		return false;
	}
}

class CChecker: public CFigure {
public:
    CChecker( char checker_color )
        : CFigure( checker_color )
    {}

	void WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
	bool CanMove();
	bool CanAttack();
	void Move( short i_row, short i_column );
	void Attack( short i_row, short i_column ); 
};

void CChecker::Move( short i_row, short i_column )
{
	std::shared_ptr<CCell> new_cell = CCell::GetBoard() -> GetCell( i_row, i_column );
	std::shared_ptr<CCell> this_cell = figure_cell_;
	figure_cell_ = new_cell;
	

}

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
		new_cell = CCell::GetBoard() -> GetCell( i_new_row, i_column + add[j] );
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
	short add[][] = { { -1, -2 }, // влево
					  {  1,  2 } // вправо
					};
	
	std::shared_ptr<CCell> enemy_cell = nullptr;
	std::shared_ptr<CCell> move_cell  = nullptr;
	for( short j = 0; j < 2; ++j ){
		enemy_cell = CCell::GetBoard() -> GetCell( i_enemy_row, i_column + add[j][0] );
		move_cell  = CCell::GetBoard() -> GetCell( i_move_row,  i_column + add[j][1] );
		if( move_cell != nullptr && move_cell -> IsEmpty() && enemy_cell -> HasFigure() &&
		    figure_color_ != enemy_cell -> GetFigure() -> GetColor() )
		{
			potential_cells.push_back( move_cell );
		}
	}
}


class CQueen: public CFigure{
public:
    CQueen( queen_color )
        : figure_color_( queen_color )
    {}

	void WhereCanMove(   std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
};

void CQueen::WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	short i_row = figure_cell_ -> GetRowNumber();
	short i_column = figure_cell_ -> GetColumnNumber();

	std::shared_ptr<CCell> new_cell = nullptr;
	// номера строк и столбцов клеток, возможных для хода
	short indices[][] = { { i_row - 1, i_column - 1 }, // левый верх
						  {	i_row - 1, i_column + 1 }, // правый верх
						  { i_row + 1, i_column - 1 }, // левый низ
						  { i_row + 1, i_column + 1 } // правый низ
						};
	// изменение номеров строк и столбцов клеток для хода
	short add[][] = { { -1, -1 }, // левый верх
					  { -1,  1 }, // правый верх
					  {  1, -1 }, // левый низ
					  {  1,  1 } // правый низ
					};

	for( short j = 0; j < 4; ++j ){
		for( short i_new_row = indices[j][0], i_new_cell = indices[j][1];
		     ( new_cell = CCell::GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
		     new_cell -> IsEmpty();
		     i_new_row += add[j][0], i_new_column += add[j][1] )
		{
			potential_cells.push_back( new_cell );
		}
	}
}

void CQueen::WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells )
{
	short i_row  = figure_cell_ -> GetRowNumber();
	short i_column = figure_cell_ -> GetColumnNumber();
	// номера строк и столбцов клеток, возможных для хода
	short indices[][] = { { i_row - 1, i_column - 1 }, // левый верх
						  {	i_row - 1, i_column + 1 }, // правый верх
						  { i_row + 1, i_column - 1 }, // левый низ
						  { i_row + 1, i_column + 1 } // правый низ
						};
	// изменение номеров строк и столбцов клеток для хода
	short add[][] = { { -1, -1 }, // левый верх
					  { -1,  1 }, // правый верх
					  {  1, -1 }, // левый низ
					  {  1,  1 } // правый низ
					};

	std::shared_ptr<CCell> new_cell = nullptr;
	
	for( short j = 0; j < 4; ++j ){
		// поиск вдоль диагонали первой клетки с фигурой
		for( short i_new_row = indices[j][0], i_new_column = indices[j][1];
		     ( new_cell = CCell::GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
			 new_cell -> IsEmpty();
			 i_new_row += add[j][0], i_new_column += add[j][1]
		);
		// клетка - в пределах доски и фигура - противника ?
		if( new_cell != nullptr && figure_color_ != new_cell -> GetFigure() ->GetColor() ){
			i_new_row += add[j][0];
			i_new_column += add[j][1];
			// отмечаем все возможные, т.е. пустые, для хода дамки клетки после атаки фигуры противника
			while( (new_cell = CCell::GetBoard() -> GetCell( i_new_row, i_new_column ) ) != nullptr &&
				   new_cell -> IsEmpty() )
			{
				potential_cells.push_back( new_cell );
			}
		}
	}
}
