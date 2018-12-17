#pragma once

#include "../ExceptionLib/Exception.h"
#include "Elem.h"

template <class T>
class TList {
protected:
  TElem <T>* begin;
public:
  TList(); //����������� �� ���������
  TList(TList<T> &L); //����������� �����������
  virtual ~TList();

  void PutBegin(T a); //�������� ������ � ������ ������
  void PutEnd(T a); //�������� ������� � ����� ������
  T GetBegin(); //����� � ��������� �� ������
  T GetEnd(); //����� � ��������� �� �����
  bool IsEmpty();

  void Print();
};

//����������� �� ���������
template <class T>
TList<T>::TList()
{
  begin = 0;
}

//���������� �����������
template <class T>
TList<T>::TList(TList<T> &L)
{
  TElem<T> *a = L.begin, *b;
  if (L.begin == 0)
    begin = 0;
  else 
  {
    begin = new TElem<T>(*L.begin); //������������ ����������� ����������� ��� Telem; ��������� �� & � ���� ��������, ��� ������ � constr copy ��� List
    b = begin;
    while (a->TElem<T>::GetNext() != 0)
    {
      b->TElem<T>::SetNext(new TElem<T>(*(a->TElem<T>::GetNext()))); //new return *, Telem - constr copy, *(a->Get) --> &
      a = a->TElem<T>::GetNext();
      b = b->TElem<T>::GetNext();
    }
  }
}

template <class T>
TList<T>::~TList() {
  while (begin != 0)          //���� �� ������ �� �����
  {
    TElem <T> *temp = begin->GetNext();   //��������� ���������� ��� �������� ������ ���������� ��������
    delete begin;                //����������� ����� ������������ ������
    begin = temp;                  //������ ����� �� ���������
  }
}

template <class T>
void TList<T>::PutBegin(T A)
{
  TElem<T>* tmp = new TElem <T>(A, begin);
  begin = tmp;
}

template <class T>
void TList<T>::PutEnd(T A)
{
  if (begin != 0) 
  {
    TElem <T> *a = begin;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElem <T>(A, 0));
  }
  else 
    begin = new TElem<T>(A, 0);
}

template <class T>
T TList<T>::GetBegin()
{
  if (IsEmpty()) 
    throw TException("List is empty.");
  TElem<T> *temp = begin;
  T tmp = begin->TElem<T>::GetData();
  begin = begin->TElem<T>::GetNext();
  delete temp;
  return tmp;
}

template <class T>
T TList<T>::GetEnd()
{
  if (IsEmpty())
    throw TException("List is empty.");
  if (begin->TElem<T>::GetNext() == 0)
  {
    T res = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    return res;
  }
  else
  {
    TElem<T> *temp = begin;
    while (temp->GetNext()->GetNext() != 0)
      temp = temp->GetNext();
    TElem<T> *temp1 = temp->GetNext();
    T res = temp1->GetData();
    delete temp1;
    temp->SetNext(0);
    return res;
  }
}

template <class T>
bool TList<T>::IsEmpty()
{
  if (begin == 0)
    return true;
  else
    return false;
}

template <class T>
void TList<T>::Print()
{
  if (IsEmpty())
    throw TException("List is empty.");
  TElem<T> *temp = begin;
  do
  {
    std::cout << "|" << temp->TElem<T>::GetData() << "| ";
    temp = temp->GetNext();
  } while (temp != 0);
  std::cout << std::endl << std::endl;
}