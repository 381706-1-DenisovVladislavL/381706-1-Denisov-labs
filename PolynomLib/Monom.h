#pragma once

#include <iostream>

class TMonom {
protected:
  TMonom* next;//Указатель на следующий
  unsigned* power;//Степени
  double c;// Коэффициент
  const int n;//Кол-во переменных
public:
  TMonom(int _n, unsigned* _power, double c);
  ~TMonom();
  TMonom(TMonom& monom);
  TMonom* GetNext();//Указатель на следующий
  unsigned* GetPower();//Степени
  double GetC();// Коэффициент
  const int GetN();//Кол-во переменных

  void SetNext(TMonom* _next);//Указатель на следующий
  void SetpPower(unsigned* _power);//Степени
  void SetC(double _c);// Коэффициент

  TMonom& operator =(TMonom& monom);
  TMonom operator +(TMonom& monom);
  TMonom operator -(TMonom& monom);
  bool operator ==(TMonom& monom);
  bool operator >(TMonom& monom);
  bool operator <(TMonom& monom);

  friend std::istream& operator >> (std::istream& _s, TMonom& Tm);
  friend std::ostream& operator << (std::ostream& _s, TMonom& Tm);

};