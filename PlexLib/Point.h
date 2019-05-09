#pragma once
#include "../ExceptionLib/Exception.h"

class TPoint
{
protected:
  double x, y; //���������� �����
public:
  TPoint(double _x=0, double _y=0); //����������� �������������

  double GetX(); //��������� X
  double GetY(); //��������� Y
  void SetX(double _x); //��������� X
  void SetY(double _y); //��������� Y

  virtual void Show(); //����� ����� �� �������
};