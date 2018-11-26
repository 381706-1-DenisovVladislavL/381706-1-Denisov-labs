#include <iostream>
#include "List.h"

int main()
{
	std::cout << "An example of using the List will be implemented here" << std::endl;
	TList <int> L1;
	L1.PutBegin(10);
	L1.PutBegin(20);
	L1.PutBegin(30);
	std::cout << L1.GetBegin() << " " << L1.GetBegin()<<' '<<L1.GetBegin();
	return 0;
}