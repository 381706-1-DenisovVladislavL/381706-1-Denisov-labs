#pragma once
#include "../ExceptionLib/Exception.h"

class TString
{
protected:
  char* str;
  int length;
public:
  friend std::istream& operator>>(std::istream &is, TString &string);
  friend std::ostream& operator<<(std::ostream &os, const TString &string);
  
  TString();
  TString(const TString &string);
  TString(const char* _str);
  ~TString();

  int GetLength();
  void DeleteStr();

  TString operator+(TString &string);
  TString& operator=(TString &string);
  char& operator[](int i);
};