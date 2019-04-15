#include "Plex.h"
TPlex::TPlex()
{
  first = NULL;
  last = NULL;
}
//............................................
TPlex::TPlex(TPoint *_first, TPoint *_last)
{
  first = _first;
  last = _last;
}
//............................................
TPlex::TPlex(TPlex &A)
{
  TPlex *l, *r;
  l = dynamic_cast <TPlex*> (A.last);
  r = dynamic_cast <TPlex*> (A.first);
  if (l != 0)//в данном случае, А.last указывает на плекс, его требуется создать
    last = new TPlex(*l);
  else
    last = new TPoint(*A.last);
  if (r != 0)//это плекс, его требуется создать
    first = new TPlex(*r);
  else
    first = new TPoint(*A.first);
}
//............................................
void TPlex::Add(TPoint *_first, TPoint *_last)
{
  if (first == 0 && last == 0)//только создали плекс
  {
    first = _first;
    last = _last;
  }
  else
  {
    TStack <TPoint*> point;
    TStack <TPlex*> plex;
    point.Put(first);
    point.Put(last);
    plex.Put(this);
    plex.Put(this);
    bool flag = true;
    while (flag && (!point.IsEmpty() || !plex.IsEmpty()))
    {
      TPoint *t = point.Get();
      TPlex *p = dynamic_cast <TPlex*> (t);
      TPlex *par = plex.Get();
      if (t->GetX() == _first->GetX() && t->GetY() == _first->GetY())
      {
        if (par->last == t)
          par->last = new TPlex(_last, _first);
        else
          par->first = new TPlex(_last, _first);
        flag = false;
      }
      else if (t->GetX() == _last->GetX() && t->GetY() == _last->GetY())
      {
        if (par->last == t)
          par->last = new TPlex(_first, _last);
        else
          par->first = new TPlex(_first, _last);
        flag = false;
      }
      else if (p != 0)
      {
        point.Put(p->last);
        point.Put(p->first);
        plex.Put(p);
        plex.Put(p);
      }
    }
    if (flag)
      throw TException("Error line");
  }
}
//............................................
TPoint* TPlex::GetFirst()
{
  return first;
}
//............................................
TPoint* TPlex::GetLast()
{
  return last;
}
//............................................
void TPlex::SetFirst(TPoint *_first)
{
  first = _first;
}
//............................................
void TPlex::SetLast(TPoint *_last)
{
  last = _last;
}
//............................................
TPoint* TPlex::Show(TPlex *p)
{
  TPlex *pl, *pr;
  TPoint *tl, *tr;
  TPoint *pp = NULL;
  pl = dynamic_cast<TPlex*>(p->last);
  pr = dynamic_cast<TPlex*>(p->first);
  if (pl != 0)//Плекс
    tl = Show(pl);
  else
    tl = p->last;
  if (pr != 0)
    tr = Show(pr);
  else
    tr = p->first;
  TLine A(*tl, *tr);
  A.Show();
  return tl;
}
//............................................
void TPlex::Show()
{
  TStack<TPlex*> St;
  TPlex *pl, *pr;
  TPlex *p = this;
  TPoint *tl = NULL, *tr = NULL;
  St.Put(p);
  while (!St.IsEmpty())
  {
    p = St.Get();
    while (tr == NULL)
    {
      pr = dynamic_cast<TPlex*>(p->first);
      if (pr != NULL) //плекс, помещаем в стек
      {
        St.Put(p);
        p = dynamic_cast<TPlex*>(pr);
      }
      else
      {
        tr = p->first;
      }
    }

    if (tl == NULL)
    {
      pl = dynamic_cast<TPlex*>(p->last);
      if (pl != NULL) //снова плекс, помещаем стек и переходим к новому плексу
      {
        St.Put(p);
        p = dynamic_cast<TPlex*>(pl);
        tr = NULL;
        St.Put(p);
      }
      else
      {
        tl = p->last;
      }
    }
    if (tr != NULL && tl != NULL)
    {
      TLine A(*tl, *tr);
      A.Show();
      if (!St.IsEmpty())
      {
        p = St.Get();
        pr = dynamic_cast<TPlex*>(p->first);
        TPoint *pp = tl;
        if (pr != 0)
        {
          tr = pp;
          tl = NULL;
        }
        else
        {
          tl = pp;
          tr = NULL;
        }
        St.Put(p);
      }
    }
  }
}
