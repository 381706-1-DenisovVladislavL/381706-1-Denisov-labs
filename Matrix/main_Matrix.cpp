#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	cout << "An example of using the Matrix will be implemented here" << endl;
	TMatrix <int> M1(5), M2(5), R(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; i < 5; j++) {
			M1[i][j] = i * 10 + j;
			M2[i][j] = (i * 10 + j) * 100;
		}
	R = M1 + M2;
	cout << "M1 =" << endl << M1 << endl;
	cout << "M2 =" << endl << M2 << endl;
	cout << "R =" << endl << R << endl;
	return 0;
}