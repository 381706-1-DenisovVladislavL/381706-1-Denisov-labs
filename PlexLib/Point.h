#pragma once
#include "../ExceptionLib/Exception.h"

class TPoint
{
protected:
  double x, y; //координаты точки
public:
  TPoint(double _x=0, double _y=0); //конструктор инициализатор

  double GetX(); //получение X
  double GetY(); //получение Y
  void SetX(double _x); //установка X
  void SetY(double _y); //установка Y

  virtual void Show(); //вывод точки на консоль
};