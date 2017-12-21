#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include <memory>
#include <vector>

#include "figure.hpp"

class CCell;

class CQueen: public CFigure{
public:
	CQueen( char queen_color, std::shared_ptr<CCell> &queen_cell );

	void WhereCanMove(   std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
};

#endif
