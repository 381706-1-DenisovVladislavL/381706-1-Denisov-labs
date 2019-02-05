#include "Monom.h"
#include "../ExceptionLib/Exception.h"

TMonom::~TMonom()
{
  delete[] power;
  c = 0;
  next = 0;
}

TMonom::TMonom(int _n, unsigned *_power, double _c):n(_n)
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

TMonom::TMonom(TMonom &monom) : n(monom.n)
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

void TMonom::SetNext(TMonom *_next)
{
  next = _next;
}

void TMonom::SetPower(unsigned *_power)
{
  try {
    for (int i = 0; i < n; i++)
      if (_power[i] >= 0)
      {
        power[i] = _power[i];
      }
      else
        throw TException("Negative power is not allowed.");
  }
  catch (...)
  {
    throw TException("Failed to change power.");
  }
}

void TMonom::SetC(double _c)
{
  c = _c;
}


TMonom& TMonom::operator=(TMonom &monom)
{
  if (this == &monom)
    return *this;
  if (n != monom.n)
    throw TException("Different number of variables.");
  c = monom.c;
  next = monom.next;
  delete[] power;
  power = new unsigned[n];
  for (int i = 0; i < n; i++)
    power[i] = monom.power[i];
  return *this;
}

TMonom TMonom::operator+(TMonom &monom)
{
  if ((n != monom.n) || !(*this == monom))
    throw TException("Different number of variables or different power.");
  TMonom temp(monom);
  temp.c = c + monom.c;
  return temp;
}
TMonom TMonom::operator-(TMonom &monom)
{
  if ((n != monom.n) || !(*this == monom))
    throw TException("Different number of variables or different power.");
  TMonom temp(monom);
  temp.c = c - monom.c;
  return temp;
}

TMonom TMonom::operator*(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different number of variables.");
  TMonom temp(monom);
  temp.c = c * monom.c;
  for (int i = 0; i < n; i++)
    temp.power[i] = this->power[i] + monom.power[i];
  return temp;
}

bool TMonom::operator==(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different number of variables or different power.");
  for (int i = 0; i < n; i++) {
    if (power[i] != monom.power[i])
      return false;
  }
  return true;
}
bool TMonom::operator>(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different number of variables or different power.");
  for (int i = 0; i < n; i++) {
    if (power[i] < monom.power[i])
      return false;
  }
  return true;

}
bool TMonom::operator<(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different number of variables or different power.");
  for (int i = 0; i < n; i++) {
    if (power[i] > monom.power[i])
      return false;
  }
  return true;

}

std::istream& operator>>(std::istream &_s, TMonom &Tm)
{
  std::cout << "\nEnter c: ";
  _s >> Tm.c;
  std::cout << "Enter power (use the gap): ";
  for (int i = 0; i < Tm.n; i++)
    _s >> Tm.power[i];
  std::cout << std::endl;
  return _s;
}

std::ostream& operator<<(std::ostream &_s, TMonom &Tm)
{
  _s << Tm.c;
  if (Tm.c != 0)
  {
    for (int i = 0; i < Tm.n; i++)
      if (Tm.power[i] != 0)
      {
        _s << "(X" << i;
        if (Tm.power[i] != 1)
          _s << "^" << Tm.power[i] << ")";
        else
          _s << ")";
      }
  }
  return _s;
}

TMonom TMonom::operator+=(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different n");
  if (!(*this == monom))
    throw TException("Different power");
  c += monom.c;
  return *this;
}

TMonom TMonom::operator-=(TMonom &monom)
{
  if (n != monom.n)
    throw TException("Different n");
  if (!(*this == monom))
    throw TException("Different power");
  c -= monom.c;
  return *this;
}