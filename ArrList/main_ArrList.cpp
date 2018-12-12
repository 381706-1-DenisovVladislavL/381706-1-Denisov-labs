#include <iostream>
#include "ArrList.h"

int main()
{
  std::cout << "An example of using the ArrList will be implemented here" << std::endl;
  TArrList <int> aList(3);
  aList.PushStart(1);
  aList.PushStart(2);
  aList.PushStart(3);
  try
  {
    aList.PushStart(4);
  }
  catch (TException exp)
  {
    exp.Print();
  }
  std::cout << aList.PullStart() << std::endl;
  std::cout << aList.PullFinish() << std::endl;
  std::cout << aList.PullFinish() << std::endl;
  try 
  {
    std::cout << aList.PullFinish() << std::endl;
  }
  catch (TException exp) 
  {
    exp.Print();
  }
  return 0;
}