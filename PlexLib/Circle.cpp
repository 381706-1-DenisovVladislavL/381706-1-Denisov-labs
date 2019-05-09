#include "Circle.h"

TCircle::TCircle()
{
	center = new TPoint(0, 0);
	radius = 1;
}

TCircle::TCircle(const TPoint* point, double rad)
{
	if (rad <= 0)
		throw TException("Error radius");
	center = new TPoint(*point);
	radius = rad;
}

TCircle::TCircle(const double _x, const double _y, const double rad)
{
	if (rad <= 0)
		throw TException("Error radius");
	center = new TPoint(_x, _y);
	radius = rad;
}

TCircle::TCircle(const TCircle& circle)
{
	center = new TPoint(*circle.center);
	radius = circle.radius;
}

TCircle::~TCircle()
{
	delete center;
	radius = 0;
}

void TCircle::SetX(const double _x)
{
	center->SetX(_x);
}

void TCircle::SetY(const double _y)
{
	center->SetY(_y);
}

void TCircle::SetRadius(const double rad)
{
	if (rad <= 0)
		throw TException("Error");
	radius = rad;
}

double TCircle::GetX()
{
	return center->GetX();
}

double TCircle::GetY()
{
	return center->GetY();
}

double TCircle::GetRadius()
{
	return radius;
}

void TCircle::Show()
{
	std::cout << "Draw: Circle \n";
	std::cout << "Center: ";
	center->Show();
	std::cout << "Radius: " << radius << std::endl;
}