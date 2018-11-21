#include <iostream>

#include "MultiStack.h"

using namespace std;

int main()
{
	cout << "An example of using the MStack will be implemented here" << endl;
	TMStack <int> MS(10,3);
	int test = MS.Test();
	cout << test;
	return 0;
}