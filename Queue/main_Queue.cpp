#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	cout << "An example of using the Queue will be implemented here" << endl;
	TQueue <int> Q(3);
	Q.Put(10);
	int a = Q.Get();
	cout << a;
	return 0;
}