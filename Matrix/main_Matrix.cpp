#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	cout << "An example of using the Matrix will be implemented here" << endl;
	TMatrix <int> M1(5), M2(5), R(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5-i; j++) {
			M1[i][j] = (i + 1) * (j + 1);
			M2[i][j] = (i * 10 + j + 3 + i) * 100;
	}
	//R = M1 + M2;
	cout << "M1 =" << endl << M1 << endl;
	cout << "M2 =" << endl << M2 << endl;
	//cout << "R =" << endl << R << endl;
//	R = M1 - M2;
//	cout << "R =" << endl << R << endl;

 // cout << "WARNING" << endl;
 // cout << "M1 =" << endl << M1 << endl;
 // cout << "M2 =" << endl << M2 << endl;
 // if (M1 == M1) cout << "Yeeh!";
 // else cout << "Noo!";

  R = M1 * M2;
  cout << "R = " << endl << R << endl;
	return 0;
}