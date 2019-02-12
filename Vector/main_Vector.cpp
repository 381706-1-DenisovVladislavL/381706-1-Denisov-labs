#include <iostream>
#include "Vector.h"

using namespace std;

//Uncomment to use the vector IO-example.
//#define __USE_EXAMPLE_IO__ 

int main() {
  cout << "An example of working with Vector."
       << endl << "Denisov Vladislav L. Group 381706-1" << endl;
  cout << "\n===============\n" << "Creating vectors..." << "\n===============\n";
  TVector <int> V1(3), V2(3), R(3);
  for (int i = 0; i < 3; i++)
  {
    V1[i] = (i + 1 - (i + 3) * 3);
    V2[i] = (i * 10 + 5 - i) * 2;
  }
  cout << "V1: " << V1 << endl;
  cout << "V2: " << V2 << endl;
  
  cout << "\n===============\n" << "Examples of arithmetic operations:" << "\n===============" << endl;
  try 
  {
    R = V1 + V2;
    cout << "Result V1 + V2: " << R << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }

  try 
  {
    R = V1 - V2;
    cout << "Result V1 - V2: " << R << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }

  try 
  {
    int k = V1 * V2;
    cout << "Result V1 * V2: " << k << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }
  
  //IO-example
#ifdef __USE_EXAMPLE_IO__
  cout << "\n===============\n" << "An example of using input / output streams:" << "\n===============";
  TVector <int> V(5);
  cin >> V;
  cout << "\nVector entered by you: " << V << endl;
  return 0;
#endif
}