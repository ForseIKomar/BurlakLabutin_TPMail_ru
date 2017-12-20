#include "figure.hpp"

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
