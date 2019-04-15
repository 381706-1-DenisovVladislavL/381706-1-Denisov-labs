#pragma once
#include "../ExceptionLib/Exception.h"

class TPoint
{
protected:
  double x, y;
public:
  TPoint(double _x=0, double _y=0);

  double GetX();
  double GetY();
  void SetX(double _x);
  void SetY(double _y);

  virtual void Show();
};

class TLine
{
protected:
  TPoint A, B;
public:
  TLine(TPoint _A, TPoint _B);
  TLine(TLine &D);

  TPoint GetA();
  TPoint GetB();
  void SetA(TPoint _A);
  void SetB(TPoint _B);

  virtual void Show();
};