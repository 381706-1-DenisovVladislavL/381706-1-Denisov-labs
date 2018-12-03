#include <iostream>

#include "MultiStack.h"

using namespace std;

int main()
{
	std::cout << "An example of using the MStack will be implemented here" << std::endl;
	TMStack <int> MS(10,3);
	MS.Print();
	MS.Put(2, 1);
  MS.Put(2, 2);
  MS.Put(2, 3);
  MS.Print();
  MS.Put(2, 4);
	MS.Print();
	//TMStack <int> M2(MS);
//	M2.Print();
  try {
    std::cout << "\tMS.Get(2): " << MS.Get(2);
    std::cout << MS.Get(2); 
    std::cout << MS.Get(2);
    std::cout << MS.Get(2);
   // std::cout << MS.Get(2);
    /*<< "\t M2.Get(1) (copied stack): " << M2.Get(2);*/
  }
  catch (TException exp) {
    exp.Print();
  }
	return 0;
}