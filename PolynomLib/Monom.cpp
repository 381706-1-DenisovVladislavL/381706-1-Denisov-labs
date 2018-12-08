#pragma once

#include "../ExceptionLib/Exception.h"
#include "Monom.h"

TMonom::~TMonom()
{
  delete[] power;
  c = 0;
  next = 0;
}

TMonom::TMonom(int _n, unsigned* _power, double _c):n(_n)
{
  if (_n <= 0)
    throw TException("Negative size parameter.");
  power = new unsigned[_n];
  if (_power != 0) {
    for (int i = 0; i < _n; i++)
      power[i] = _power[i];
  }
  else {
    for (int i = 0; i < _n; i++)
      power[i] = 0;
  }
  c = _c;
  next = 0;
}

TMonom::TMonom(TMonom& monom) : n(monom.n)
{
  c = monom.c;
  next = monom.next;
  power = new unsigned[n];
  for (int i = 0; i < n; i++) {
    power[i] = monom.power[i];
  }
}

TMonom* TMonom::GetNext()
{
  return next;
}

unsigned* TMonom::GetPower()
{
  return power;
}

double TMonom::GetC()
{
  return c;
}
const int TMonom::GetN()
{
  return n;
}

void TMonom::SetNext(TMonom* _next)
{
  next = _next;
}

void TMonom::SetpPower(unsigned* _power)
{
  try {
    for (int i = 0; i < n; i++)
      if (_power[i] >= 0)
      {
        power[i] = _power[i];
      }
      else
        throw 1;
  }
  catch (...)
  {
    throw 2;
  }
}

void TMonom::SetC(double _c)
{
  c = _c;
}


TMonom& TMonom::operator =(TMonom& monom)
{
  if (this != &monom)
  {
    c = monom.c;
    if (n != monom.n)
      throw 1;
    for (int i = 0; i < n; i++)
      power[i] = monom.power[i];
    next = monom.next;
  }
}

TMonom TMonom::operator +(TMonom& monom)
{
  if (n != monom.n || !(*this == monom))
    throw 1;
  TMonom temp(monom);
  temp.c = c + monom.c;
  return temp;
}
TMonom TMonom::operator -(TMonom& monom)
{
  if ((n != monom.n) || !(*this == monom))
    throw 1;
  TMonom temp(monom);
  temp.c = c - monom.c;
  return temp;
}
bool TMonom::operator ==(TMonom& monom)
{
  if (n != monom.n)
    throw 1;
  for (int i = 0; i < n; i++) {
    if (power[i] != monom.power[i])
      return false;
  }
  return true;
}
bool TMonom::operator >(TMonom& monom)
{
  if (n != monom.n)
    throw 1;

  for (int i = 0; i < n; i++) {
    if (power[i] < monom.power[i])
      return false;
  }
  return true;

}
bool TMonom::operator <(TMonom& monom)
{
  if (n != monom.n)
    throw 1;
  for (int i = 0; i < n; i++) {
    if (power[i] > monom.power[i])
      return false;
  }
  return true;

}

std::istream& operator >> (std::istream& _s, TMonom& Tm)
{
  std::cout << "\nEnter c: ";
  _s >> Tm.c;
  std::cout << "Enter power (use the gap): ";
  for (int i = 0; i < Tm.n; i++)
    _s >> Tm.power[i];
  std::cout << std::endl;
  return _s;
}

std::ostream& operator << (std::ostream& _s, TMonom& Tm)
{
  _s << Tm.c;
  if (Tm.c != 0)
  {
    for (int i = 0; i < Tm.n; i++)
      if (Tm.power[i] != 0)
      {
        _s << "X" << i;
        if (Tm.power[i] != 1)
          _s << "^" << Tm.power[i] << " ";
      }
  }
  return _s;
}
