#pragma once

#include <iostream>
#include <string>

class TException {
private:
	std::string str;
public:
	TException(std::string _str);
	void Print();
};

TException::TException(std::string _str) : str(_str) {}

void TException::Print() {
	std::cout << "\nError! \nMessage: " << str << std::endl;
}