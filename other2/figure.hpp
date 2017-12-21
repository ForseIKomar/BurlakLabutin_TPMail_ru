#ifndef __FIGURE_HPP__
#define __FIGURE_HPP__

#include <memory>
#include <vector>

//#include "cell.h"
#include "point.hpp"

class CCell;

class CFigure{
protected:
	char figure_color_;
    std::shared_ptr<CCell> figure_cell_; // клетка, на которой расположена фигура
public:
	CFigure( char figure_color, std::shared_ptr<CCell> &figure_cell );
	~CFigure();

	char GetColor();
	std::shared_ptr<CCell>& GetCell();

	virtual void WhereCanMove(   std::vector<std::shared_ptr<CCell>> &potential_cells ) = 0;
	virtual void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells ) = 0;
	
	bool CanMove();
	bool CanAttack();
	
//	void Move(   short i_row, short i_column ) = 0; // ход в данную клетку - не реализован
//	void Attack( short i_row, short i_column ) = 0; // атаковать и перейти в данную клетку - не реализован
};

#endif
