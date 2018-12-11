#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
  cout << "An example of working with Stack."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  cout << "\nEnter the number of elements in the stack: ";
  try 
  {
    int n;
    cin >> n;
    TStack <int> stack(n);
    cout << "Enter the elements of the stack: ";
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      stack.Put(k); //Добавляем элементы в стек
    }
    stack.Print(); // печать стека
   
    cout << "\n\nGet the element of the stack: " << stack.Get() << endl; //возьмем элемент с удалением
 
    stack.Print(); // печать стека

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