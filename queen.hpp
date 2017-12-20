#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include <memory>
#include <vector>

#include "cell.hpp"
#include "figure.hpp"

class CQueen: public CFigure{
public:
CQueen( char queen_color );

	void WhereCanMove(   std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
};

#endif
