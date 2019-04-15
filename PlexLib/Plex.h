#pragma once
#include "../ExceptionLib/Exception.h"
#include "../PlexLib/Point.h"
#include "../StackLib/Stack.h"


class TPlex :public TPoint
{
protected:
  TPoint *first, *last;
public:
  TPlex();
  TPlex(TPoint *_first, TPoint *_last);
  TPlex(TPlex &A);

  void Add(TPoint *_first, TPoint *_last);
  TPoint* GetFirst();
  TPoint* GetLast();
  void SetFirst(TPoint *_first);
  void SetLast(TPoint *_last);

  void Show();
  TPoint* Show(TPlex *p);
};