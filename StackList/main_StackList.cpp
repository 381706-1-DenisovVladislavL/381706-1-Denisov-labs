#include <iostream>
#include "StackList.h"

//Uncomment to use the stack I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with StackList."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  cout << "\nEnter the number of elements in the stack: ";
  try
  {
    int n = 3;
#ifdef __USE_EXAMPLE_IO__
    cin >> n;
#endif
#ifndef __USE_EXAMPLE_IO__
    cout << n << endl;
#endif
    TStackList <int> stack;
    cout << "Enter the elements of the stack (use the gap): ";
    for (int i = 0; i < n; i++)
    {
      int k;
#ifdef __USE_EXAMPLE_IO__
      cin >> k;
#endif
#ifndef __USE_EXAMPLE_IO__
      k = i;
      cout << k << " ";
#endif
      stack.Put(k);
    }
#ifndef __USE_EXAMPLE_IO__
    cout << endl;
#endif
    stack.Print();

    cout << "\nGet the element of the stack: " << stack.Get() << endl;

    stack.Print();

    TStackList <int> stackOther(stack);
    cout << "\nCopy constructor (adress of oldStack: " << &stack << ", adress of newStack: " << &stackOther << "): " << endl;
    stackOther.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  return 0;
}