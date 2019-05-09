#include "Line.h"

TLine::TLine()
{
	point1 = new TPoint(0, 0);
	point2 = new TPoint(0, 0);
	del_flag_1 = false;
	del_flag_2 = false;
}

TLine::TLine(const TPoint* _point_1, const TPoint* _point_2)
{
	point1 = new TPoint(*_point_1);
	point2 = new TPoint(*_point_2);
	del_flag_1 = false;
	del_flag_2 = false;
}

TLine::TLine(const double x1, const double y1, const double x2, const double y2)
{
	point1 = new TPoint(x1, y1);
	point2 = new TPoint(x2, y2);
	del_flag_1 = false;
	del_flag_2 = false;
}

TLine::TLine(const TLine& line)
{
	point1 = new TPoint(*line.point1);
	point2 = new TPoint(*line.point2);
	del_flag_1 = false;
	del_flag_2 = false;
}

TLine::~TLine()
{
	if (del_flag_1 == false)
		delete point1;
	if (del_flag_2 == false)
		delete point2;
}

void TLine::SetX1(const double _x1)
{
	point1->SetX(_x1);
}

void TLine::SetY1(const double _y1)
{
	point1->SetY(_y1);
}

void TLine::SetX2(const double _x2)
{
	point2->SetX(_x2);
}

void TLine::SetY2(const double _y2)
{
	point2->SetY(_y2);
}

double TLine::GetX1()
{
	return point1->GetX();
}

double TLine::GetY1()
{
	return point1->GetY();
}

double TLine::GetX2()
{
	return point2->GetX();
}

double TLine::GetY2()
{
	return point2->GetY();
}

TPoint* TLine::GetPoint1()
{
	return point1;
}

TPoint* TLine::GetPoint2()
{
	return point2;
}

void TLine::SetPoint1(TPoint* _point1)
{
	delete point1;
	point1 = _point1;
	del_flag_1 = true;
}

void TLine::SetPoint2(TPoint* _point2)
{
	delete point2;
	point2 = _point2;
	del_flag_2 = true;
}

void TLine::Show()
{
	std::cout << "Draw: Line ( " << point1->GetX() << " , " << point1->GetY() << " ) ----- ( " << point2->GetX() << " , " << point2->GetY() << " )\n";
}