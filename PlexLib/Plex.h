#pragma once
#include "../ExceptionLib/Exception.h"
#include "../StackListLib/StackList.h"
#include "../PlexLib/Line.h"

class TPlex :public TPoint
{
protected:
  TPoint *right, *left;
public:
  TPlex(); //конструктор по умолчанию
  TPlex(TPoint *_right, TPoint *_left); //конструктор от двух точек
  TPlex(TPlex& plex); //конструктор копирования

  TPoint* GetRight(); //получить правую сторону плекса
  TPoint* GetLeft(); //получить левую сторону плекса

  void Add(TPoint *_right, TPoint *_left); //добавить линию к плексу
  void SetRight(TPoint *_right); //установить правую сторону плекса
  void SetLeft(TPoint *_left); //установить левую сторону плекса

  void Show(); //итеративный вывод плекса на консоль
  TPoint* Show(TPlex *plex); //рекурсивный вывод плекса на консоль
};