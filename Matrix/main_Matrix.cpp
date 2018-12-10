#include <iostream>
#include "Matrix.h"

//Uncomment to use the vector I/o example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with upper-triangular matrix."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  cout << "\n===============\n" << "Creating matrix..." << "\n===============\n";
  TMatrix <int> M1(5), M2(5), R(5);
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5 - i; j++) {
      M1[i][j] = (i + 1) * (j + 1);
      M2[i][j] = (i * 10 + j + 3 + i) * 8;
    }
  cout << "M1:" << endl << M1 << endl;
  cout << "M2:" << endl << M2 << endl;

  cout << "\n===============\n" << "Examples of arithmetic operations:" << "\n===============" << endl;
  try {
    R = M1 + M2;
    cout << "Result M1 + M2:" << endl << R << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }

  try {
    R = M1 - M2;
    cout << "Result M1 - M2:" << endl << R << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }

  try {
    R = M1 * M2;
    cout << "Result M1 * M2:" << endl << R << endl;
  }
  catch (TException exp)
  {
    exp.Print();
  }

  //IO-example
#ifdef __USE_EXAMPLE_IO__
  cout << "===============\n" << "An example of using input / output streams:" << "\n===============";
  TMatrix <int> MT(3);
  cin >> MT;
  cout << "\nMatrix entered by you:" << endl << MT;
  try
  {
    R = M1 + MT;
  }
  catch (TException exp)
  {
    exp.Print();
  }
#endif
	return 0;
}