#include "Point.h"

TPoint::TPoint(double _x, double _y)
{
  x = _x;
  y = _y;
}
//...........................................
double TPoint::GetX()
{
  return x;
}
//...........................................
double TPoint::GetY()
{
  return y;
}
//...........................................
void TPoint::SetX(double _x)
{
  x=_x;
}
//...........................................
void TPoint::SetY(double _y)
{
  y = _y;
}
void TPoint:: Show()
{
  std::cout << "Нарисована точка с координатами( " << x << " , " << y << " )\n";
}



//...........................................
TLine::TLine(TPoint _A, TPoint _B)
{
  A = _A;
  B = _B;
}
//...........................................
TLine::TLine(TLine &D)
{
  A = D.A;
  B = D.B;
}
//...........................................
TPoint TLine::GetA()
{
  return A;
}
//...........................................
TPoint TLine::GetB()
{
  return B;
}
//...........................................
void TLine::SetA(TPoint _A)
{
  A = _A;
}
//...........................................
void TLine::SetB(TPoint _B)
{
  B = _B;
}
void TLine::Show()
{
  std::cout << "Нарисован отрезок с координатами ( " << A.GetX() << " , " << A.GetY() << " ) ( " << B.GetX() << " , " << B.GetY() << " )\n";
}