#ifndef __CHECKER_HPP__
#define __CHECKER_HPP__

#include <memory>
#include <vector>

#include "cell.hpp"
#include "figure.hpp"

class CChecker: public CFigure {
public:
    CChecker( char checker_color );

	void WhereCanMove( std::vector<std::shared_ptr<CCell>> &potential_cells );
	void WhereCanAttack( std::vector<std::shared_ptr<CCell>> &potential_cells );
	
	//bool CanMove();
	//bool CanAttack();
	
	//void Move( short i_row, short i_column );
	//void Attack( short i_row, short i_column );

	CChecker& operator = ( const CChecker &current_checker );
};

#endif
