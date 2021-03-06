#pragma once
#include "Monom.h"

class TPolynom {
protected:
  TMonom *start; //��������� �� ������ ��������
  int n; //x1x2...xn
public:
  TPolynom(int _n);
  TPolynom(TPolynom &p);
  virtual ~TPolynom();    
  
  TMonom* GetStart();

  TPolynom& operator=(const TPolynom &p);
  TPolynom& operator+=(TMonom &m);
  TPolynom operator+(TPolynom &p);
  TPolynom operator*(TPolynom &p);
  
  bool operator==(const TPolynom &p);  
  
  friend std::ostream& operator<<(std::ostream& _s, TPolynom& Tm);
};