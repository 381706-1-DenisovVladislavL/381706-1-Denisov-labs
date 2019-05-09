#include "Point.h"

TPoint::TPoint(double _x, double _y)
{
	x = _x;
	y = _y;
}

double TPoint::GetX()
{
	return x;
}

double TPoint::GetY()
{
	return y;
}

void TPoint::SetX(double _x)
{
	x = _x;
}

void TPoint::SetY(double _y)
{
	y = _y;
}
void TPoint::Show()
{
	std::cout << "Draw: Point (" << x << " , " << y << " )\n";
}