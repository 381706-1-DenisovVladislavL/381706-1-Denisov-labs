#pragma once
#include "../ExceptionLib/Exception.h"
#include "../StackListLib/StackList.h"
#include "../PlexLib/Line.h"

class TPlex :public TPoint
{
protected:
  TPoint *right, *left;
public:
  TPlex(); //����������� �� ���������
  TPlex(TPoint *_right, TPoint *_left); //����������� �� ���� �����
  TPlex(TPlex& plex); //����������� �����������

  TPoint* GetRight(); //�������� ������ ������� ������
  TPoint* GetLeft(); //�������� ����� ������� ������

  void Add(TPoint *_right, TPoint *_left); //�������� ����� � ������
  void SetRight(TPoint *_right); //���������� ������ ������� ������
  void SetLeft(TPoint *_left); //���������� ����� ������� ������

  void Show(); //����������� ����� ������ �� �������
  TPoint* Show(TPlex *plex); //����������� ����� ������ �� �������
};