#include <iostream>
#include "Polynom.h"

int main()
{
  std::cout << "An example of working with Polynoms."
    << std::endl << "Denisov Vladislav L. Group 381706-1\n" << std::endl;
  
  unsigned arr1[] = { 1, 2, 3 };
  unsigned arr2[] = { 4, 5, 6 };
  unsigned arr3[] = { 0, 8, 9 };
  unsigned arr4[] = { 3, 4, 4 };
  unsigned arr5[] = { 2, 6, 7 };
  unsigned arr6[] = { 5, 0, 3 };
  TMonom m1(3, arr1, 1);
  TMonom m2(3, arr2, 2);
  TMonom m3(3, arr3, 4);
  TMonom m4(3, arr4, 0);
  TMonom m5(3, arr5, 5);
  TMonom m6(3, arr6, 6);
  
  std::cout << "Monom m1: " << m1 << std::endl;
  std::cout << "Monom m2: " << m2 << std::endl;
  std::cout << "Monom m3: " << m3 << std::endl;
  std::cout << "Monom m4: " << m4 << std::endl;
  std::cout << "Monom m5: " << m5 << std::endl;
  std::cout << "Monom m6: " << m6 << std::endl;
  
  TPolynom poly1(3);
  poly1 += m1;
  poly1 += m2;
  poly1 += m3;
  std::cout << "\nPolynom poly1 [m1 + m2 + m3]: " << poly1 << std::endl;

  TPolynom poly2(3);
  poly2 += m4;
  poly2 += m5;
  poly2 += m6;
  std::cout << "Polynom poly2 [m4 + m5 + m6]: " << poly2 << std::endl;

  TPolynom result(3);
  result = poly1 + poly2;
  std::cout << "\nResult poly1 + poly2: " << result << std::endl;

  result = poly1 * poly2;
  std::cout << "Result poly1 * poly2: " << result << std::endl;
  
  TPolynom poly1Copy(poly1);
  std::cout << "\nCopy constructor (adress of poly1: " << &poly1 << ", adress of poly1Copy: " << &poly1Copy << "): ";
  std::cout << "\nPolynom poly1Copy: " << poly1Copy << std::endl;

  std::cout << "\nDemonstration of monomial input using the console.";
  TMonom consoleMonom(3, 0, 0);
  std::cin >> consoleMonom; 
  std::cout << "consoleMonom: " << consoleMonom << std::endl;

  return 0;
}