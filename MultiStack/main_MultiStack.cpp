#include <iostream>

#include "MultiStack.h"

using namespace std;

int main()
{
	cout << "An example of using the MStack will be implemented here" << endl;
	TMStack <int> MS(10,3);
	int test = MS.Test();
	MS.Put(1, 20);
	cout << test << "\t" << MS.Get(1);
	return 0;
}