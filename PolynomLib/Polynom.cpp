#include "Polynom.h"
#include "../ExceptionLib/Exception.h"

TPolynom::TPolynom(int _n) 
{
  if (_n <= 0)
    throw TException("Negative size parameter.");
  n = _n;
  start = 0;
}

TPolynom::TPolynom(TPolynom &p) 
{
  n = p.n;
  if (p.start == 0)
    start = 0;
  else
  {
    start = new TMonom(*p.start);
    TMonom *_start = p.start;
    TMonom *_pstart = start;
    while (_start->GetNext() != 0)
    {
      _pstart->SetNext(new TMonom(*(_start->GetNext())));
      _pstart = _pstart->GetNext();
      _start = _start->GetNext();
    }
    _pstart->SetNext(0);
  }
}

TPolynom::~TPolynom() {}

TMonom* TPolynom::GetStart()
{
  return start;
}

TPolynom& TPolynom::operator=(TPolynom &p) 
{
  if (this == &p)
    return *this;
  TMonom *_start1 = start, *_start2 = start;
  while (_start1 != 0) //очищаем полином, в который будем производить присваивание
  {
    _start1 = _start1->GetNext();
    delete _start2;
    _start2 = _start1;
  }
  _start1 = p.start->GetNext();
  _start2 = new TMonom(*p.start);
  start = _start2;
  while (_start1 != 0) //выполняем копирование данных из правого операнда
  {
    _start2->SetNext(new TMonom(*_start1));
    _start2 = _start2->GetNext();
    _start1 = _start1->GetNext();
  }
  return *this;
}

TPolynom& TPolynom::operator+=(TMonom &m)
{
  if (this->n != m.GetN())
    throw TException("Different number of variables.");
  if (m.GetC() == 0)
    return *this;
  if (start == 0)
    start = new TMonom(m);
  else
  {
    TMonom *_start, *_end;
    _start = start;
    _end = start->GetNext();
    //выполняем поиск подходящей позиции для монома, который хотим добавить к полиному. Должен соблюдться лексикографический порядок
    if (*start < m)
    {
      TMonom *tmp = new TMonom(m);
      tmp->SetNext(start);
      start = tmp;
    }
    else 
      if (*start == m)
      {
        *start += m;
        if (start->GetC() == 0)
        {
          TMonom *temp = start->GetNext();
          delete[] start;
          start = temp;
        }
      }
      else
      {
        while (_end != 0)
        {
          if (*_end == m)
          {
            *_end += m;
            if (_end->GetC() == 0)
            {
              start->SetNext(_end->GetNext());
              delete[] _end;
            }
            return *this;
          }
          if (*_end < m)
          {
            TMonom *tmp = new TMonom(m);
            _start->SetNext(tmp);
            tmp->SetNext(_end);
            return *this;
          }
          _start = _end;
          _end = _end->GetNext();
        }
        _start->SetNext(new TMonom(m));
      }
  }
  return *this;
}
 
TPolynom TPolynom::operator+(TPolynom &p)
{
  if (this->n != p.n)
    throw TException("Different number of variables.");
  TPolynom temp(n);
  TMonom *_start = start, *_pstart = p.start, *i = temp.start;
  while ((_start != 0) && (_pstart != 0))
  {
    TMonom *_monom;
    if ((*_start) == (*_pstart))
    {
      _monom = new TMonom((*_start) + (*_pstart));
      _start = _start->GetNext();
      _pstart = _pstart->GetNext();
    }
    else
    {
      if ((*_start) < (*_pstart))
      {
        _monom = new TMonom(*_pstart);
        _pstart = _pstart->GetNext();
      }
      else
      {
        _monom = new TMonom(*_start);
        _start = _start->GetNext();
      }
    }
    if (i == 0)
    {
      i = _monom; //переходим к _monom
      temp.start = _monom; //если полином пустой, то туда впихиваем _monom
    }
    else
    {
      i->SetNext(_monom); //добавляем _monom к полиному, если он не пустой
      i = i->GetNext(); 
    }
  }
  if (_start == 0)
    _start = _pstart; //если дошли до конца первого полинома, то перекидываем итератор второго на первый
  while (_start != 0) //докидываем остаток
  {
    i->SetNext(new TMonom(*_start));
    _start = _start->GetNext();
    i = i->GetNext();
  }
  return temp;
}

TPolynom TPolynom::operator*(TPolynom &p) 
{
  if (this->n != p.n)
    throw TException("Different number of variables.");
  TPolynom temp(n);
  TMonom *_start = start;
  TMonom *_pstart = p.start;
  while (_start != 0)
  {
    if (_start->GetC() == 0)
      continue;
    while (_pstart != 0)
    {
      if (_pstart->GetC() == 0)
        continue;
      TMonom k = (*_start);
      k = k * (*_pstart);
      TMonom *_k = new TMonom(k);
      _k->SetNext(0);
      temp += *_k;
      _pstart = _pstart->GetNext();
    }
    _start = _start->GetNext();
    _pstart = p.start;
  }
  return temp;
}

bool TPolynom::operator==(TPolynom &p) 
{
  if (this->n != p.n)
    throw TException("Different number of variables.");
  TMonom *_start = start;
  TMonom *_pstart = p.start;
  while (_start != 0)
  {
    if (!(*_start == *_pstart))
      return false;
    if (_start->GetC() != _pstart->GetC())
      return false;
    _start = _start->GetNext();
    _pstart = _pstart->GetNext();
  }
  return true;
}
 
std::ostream& operator<<(std::ostream &_s, TPolynom &poly)
{
  TMonom *_start = poly.start;
  if (_start != 0)
  {
    _s << *_start;
    _start = _start->GetNext();
  }
  while (_start != 0)
  {
    if (_start->GetC() != 0)
      _s << " + " << *_start;
    _start = _start->GetNext();
  }
  return _s;
}