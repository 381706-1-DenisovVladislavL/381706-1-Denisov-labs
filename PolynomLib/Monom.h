#pragma once
#include "../ExceptionLib/Exception.h"

class TMonom {
protected:
  TMonom *next;//Указатель на следующий моном
  unsigned *power;//Степени
  double c;//Коэффициент
  const int n;//Кол-во переменных
public:
  TMonom(int _n, unsigned *_power, double c);
  TMonom(TMonom& monom); 
  virtual ~TMonom(); 

  TMonom* GetNext(); //Получить указатель на следующий моном
  unsigned* GetPower(); //Получить степени
  double GetC(); //Получить коэффициент
  const int GetN(); //Получить кол-во переменных

  void SetNext(TMonom *_next); //Установить указатель на следующий моном
  void SetPower(unsigned *_power); //Изменить степени
  void SetC(double _c); //Изменить коэффициент

  TMonom& operator=(const TMonom &monom);
  TMonom operator+(TMonom &monom);
  TMonom operator+=(TMonom &monom);
  TMonom operator-(TMonom &monom);
  TMonom operator-=(TMonom &monom);
  TMonom operator*(TMonom &monom) const;
  TMonom operator*=(TMonom &monom);
  bool operator==(TMonom &monom);
  bool operator>(TMonom &monom);
  bool operator<(TMonom &monom);

  friend std::istream& operator>>(std::istream &_s, TMonom &Tm);
  friend std::ostream& operator<<(std::ostream &_s, TMonom &Tm);

};