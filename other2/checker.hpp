#ifndef __CHECKER_HPP__
#define __CHECKER_HPP__

#include <memory>
#include <vector>

#include "figure.hpp"

class CCell;

class CChecker: public CFigure{
public:
    CChecker( char checker_color, std::shared_ptr<CCell> &checker_cell );

	void WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
	
	//bool CanMove();
	//bool CanAttack();
	
	//void Move( short i_row, short i_column );
	//void Attack( short i_row, short i_column );

    //CChecker& operator = ( CChecker &current_checker );
};

#endif
