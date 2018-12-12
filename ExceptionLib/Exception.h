#pragma once

#include <iostream>
#include <string>

class TException {
private:
  std::string msg;
public:
  TException(std::string _msg);
  void Print();
};

TException::TException(std::string _msg) : msg(_msg) {}

void TException::Print() {
  std::cout << "\nWarning! \nMessage: " << msg << std::endl;
}