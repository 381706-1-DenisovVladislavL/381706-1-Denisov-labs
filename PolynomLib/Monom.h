#pragma once
#include <iostream>

class TMonom {
protected:
  TMonom *next;//��������� �� ��������� �����
  unsigned *power;//�������
  double c;//�����������
  const int n;//���-�� ����������
public:
  TMonom(int _n, unsigned *_power, double c);
  TMonom(TMonom& monom); 
  virtual ~TMonom(); 

  TMonom* GetNext(); //�������� ��������� �� ��������� �����
  unsigned* GetPower(); //�������� �������
  double GetC(); //�������� �����������
  const int GetN(); //�������� ���-�� ����������

  void SetNext(TMonom *_next); //���������� ��������� �� ��������� �����
  void SetPower(unsigned *_power); //�������� �������
  void SetC(double _c); //�������� �����������

  TMonom& operator=(TMonom &monom);
  TMonom operator+(TMonom &monom);
  TMonom operator+=(TMonom &monom);
  TMonom operator-(TMonom &monom);
  TMonom operator-=(TMonom &monom);
  TMonom operator*(TMonom &monom);
  TMonom operator*=(TMonom &monom);
  bool operator==(TMonom &monom);
  bool operator>(TMonom &monom);
  bool operator<(TMonom &monom);

  friend std::istream& operator>>(std::istream &_s, TMonom &Tm);
  friend std::ostream& operator<<(std::ostream &_s, TMonom &Tm);

};