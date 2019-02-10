#include "Polish.h"

int main()
{
  try
  {
    std::cout << "An example of working with ReversePolishNotation."
      << std::endl << "Denisov Vladislav L. Group 381706-1" << std::endl;

    std::cout << "\nEnter your math expression: ";
    char arr[] = "16/4-(2+3)*4+(5-2)/2";
    TString inputStr(arr);
    //std::cin >> inputStr;
    TQueue<char> reversePolishNotation;
    reversePolishNotation = ConvertToPol(inputStr);
    std::cout << "\nYour entered expression:\n" << inputStr << "\nhas been converted to Reverse Polish Notation:\n";
    reversePolishNotation.Print();
    std::cout << "\nResult: " << Calculate(reversePolishNotation) << std::endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }
  return 0;
}
