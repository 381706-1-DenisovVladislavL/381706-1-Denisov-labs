#pragma once
#include "Monom.h"

class TPolynom {
protected:
  TMonom *start; //указатель на начало полинома
  int n; //x1x2...xn
public:
  TPolynom(int _n);
  TPolynom(TPolynom &p);
  virtual ~TPolynom();    
  
  TMonom* TPolynom::GetStart();

  TPolynom& operator=(TPolynom &p);
  TPolynom& operator+=(TMonom &m);
  TPolynom operator+(TPolynom &p);
  TPolynom operator*(TPolynom &p);
  
  bool operator==(TPolynom &p);  
  
  friend std::ostream& operator<<(std::ostream& _s, TPolynom& Tm);
};