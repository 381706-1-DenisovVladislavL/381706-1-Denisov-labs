#include "MyString.h"

TString::TString()
{
	str = 0;
	length = 0;
}

TString::TString(TString &string)
{
	length = string.length;
	if (length != 0)
	{
		str = new char[length];
		for (int i = 0; i < length; i++)
			str[i] = string.str[i];
	}
	else
		str = 0;
}

TString::TString(char* _str) 
{
  if (_str == 0)
    throw TException("Empty string.");
  if (_str[0] == '\0')
    return;
  char x = 1;
  int size = 0;
  while (x != '\0')
  {
    size++;
    x = _str[size];
  }

  length = size + 1; 
  str = new char[length];
  for (int i = 0; i < length - 1; i++)
    str[i] = _str[i];
  str[length - 1] = 0;
}

TString::~TString()
{
	if (str != 0)
		delete [] str;
}

int TString::GetLength()
{
	return length;
}

void TString::DeleteStr()
{
	if (str != 0)
		delete [] str;
}

TString TString::operator+(TString &string)
{
	TString resstring;
	resstring.length = length + string.length - 1; 
	resstring.str = new char[resstring.length];
	for (int i = 0; i < length - 1; i++)
		resstring.str[i] = str[i];
	for (int i = length - 1; i < resstring.length; i++)
		resstring.str[i] = string.str[i - (length - 1)];
	return resstring;
}

TString& TString::operator=(TString &string)
{
	if (this != &string)
	{
		length = string.length;
		if (length != 0)
		{
			if (str != 0)
				delete[] str;
			str = new char[string.length];
			for (int i = 0; i < string.length; i++)
				str[i] = string.str[i];
		}
		else
		{
			if (str != 0)
				delete[] str;
			str = 0;
		}
	}
	return *this;
}

char& TString::operator[](int i)
{
  if ((i >= 0) && (i < length))
    return str[i];
  throw TException("Out-of-range.");
}

std::istream& operator>>(std::istream &is, TString &string)
{
	char s[256] = {0};
	is >> s;

  char x = 1;
  int size = 0;
  while (x != '\0')
  {
    size++;
    x = s[size];
  }
	string.length = size + 1;
	string.str = new char[string.length];
	for (int i = 0; i < string.length - 1; i++)
		string.str[i] = s[i];
	string.str[string.length - 1] = 0;
	return is;
}

std::ostream& operator<<(std::ostream &os, const TString &string)
{
	os << string.str;
	return os;
}