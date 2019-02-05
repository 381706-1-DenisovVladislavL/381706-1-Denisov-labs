#pragma once

#include <iostream>
#include <string>

class TException {
private:
  std::string msg;
public:
  TException(std::string _msg) : msg(_msg) {}
  void Print() 
  {
    std::cout << "\nWarning! \nMessage: " << msg << std::endl;
  }
};