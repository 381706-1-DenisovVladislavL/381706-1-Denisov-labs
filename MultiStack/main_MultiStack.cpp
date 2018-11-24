#include <iostream>

#include "MultiStack.h"

using namespace std;

int main()
{
	std::cout << "An example of using the MStack will be implemented here" << std::endl;
	TMStack <int> MS(10,3);
	MS.Print();
	int test = MS.Test();
	MS.Put(1, 5);
	MS.Print();
	TMStack <int> M2(MS);
	M2.Print();
	std::cout << test << "\tMS.Get(1): " << MS.Get(1) << "\t M2.Get(1) (copied stack): " << M2.Get(1);
	return 0;
}