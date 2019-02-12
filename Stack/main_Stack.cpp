#include <iostream>
#include "Stack.h"

//Uncomment to use the stack I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with Stack."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  cout << "\nEnter the number of elements in the stack: ";
  try 
  {
    int n = 3;
    #ifdef __USE_EXAMPLE_IO__
      cin >> n;
    #endif
    TStack <int> stack(n);
    cout << "Enter the elements of the stack: \n";
    for (int i = 0; i < n; i++)
    {
      int k;
      #ifdef __USE_EXAMPLE_IO__
        cin >> k;
      #endif
      #ifndef __USE_EXAMPLE_IO__
        k = i;
      #endif
      stack.Put(k);
    }
    stack.Print();
   
    cout << "\n\nGet the element of the stack: " << stack.Get() << endl;
 
    stack.Print();

    TStack <int> stackOther(stack);
    cout << "\n\nCopy constructor (adress of oldStack: " << &stack << ", adress of newStack: " << &stackOther << "): " << endl;
    stackOther.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  return 0;
}