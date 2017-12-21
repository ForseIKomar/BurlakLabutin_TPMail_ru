#include "cell.h"

CCell::CCell( SPoint point )
	: point_( point ), figure_( nullptr )
{}


void CCell::SetFigure( std::shared_ptr<CFigure> figure )
{
    figure_ = figure;
}

/*
void CCell::SetBoard( std::shared_ptr<CBoard>& board )
{
    CCell::game_field_ = board;
}


std::shared_ptr<CBoard>& CCell::GetBoard()
{
	return CCell::game_field_;
}
 
*/
std::shared_ptr<CFigure>& CCell::GetFigure()
{
    return figure_;
}

    
bool CCell::IsEmpty()
{
	return ( figure_ == nullptr ) ? true : false;
}
    
    
bool CCell::HasFigure()
{
	return ( figure_ != nullptr ) ? true : false;
}


short CCell::GetRowNumber()
{
	return point_.y;
}


short CCell::GetColumnNumber()
{
	return point_.x;
}
