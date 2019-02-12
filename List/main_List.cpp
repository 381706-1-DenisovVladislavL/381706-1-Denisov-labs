#include <iostream>
#include "List.h"

//Uncomment to use the list I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with List."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  TList <int> list;
#ifdef __USE_EXAMPLE_IO__
  int elem;
  try
  {
    list.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  cout << "\nEnter the elements of the List: \n";
  cout << "To put [begin]: ";
  cin >> elem;
  list.PutBegin(elem);
  list.Print();

  cout << "To put [end]: ";
  cin >> elem;
  list.PutEnd(elem);
  list.Print();

  cout << "To put [begin]: ";
  cin >> elem;
  list.PutBegin(elem);
  list.Print();

  cout << "To put [end]: ";
  cin >> elem;
  list.PutEnd(elem);
  list.Print();

  cout << "Get end: " << list.GetEnd() << endl;
  list.Print();

  cout << "Get end: " << list.GetEnd() << endl;
  list.Print();

  cout << "Get begin: " << list.GetBegin() << endl;
  list.Print();

  cout << "Get begin: " << list.GetBegin() << endl;
  try 
  {
    list.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  cout << "\nTo put [end]: ";
  cin >> elem;
  list.PutEnd(elem);
  list.Print();

  cout << "To put [begin]: ";
  cin >> elem;
  list.PutBegin(elem);
  list.Print();
#endif 
#ifndef __USE_EXAMPLE_IO__
  try
  {
    list.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  cout << "\nEnter the elements of the List: \n";
  cout << "To put [begin]: 5" << endl;
  list.PutBegin(5);
  list.Print();

  cout << "To put [end]: 34" << endl;
  list.PutEnd(34);
  list.Print();

  cout << "To put [begin]: 123" << endl;
  list.PutBegin(123);
  list.Print();

  cout << "To put [end]: 992" << endl;
  list.PutEnd(992);
  list.Print();

  cout << "To put in pos [1]: 10" << endl;
  list.Put(1, 10);
  list.Print();

  cout << "To get in pos [1]: " << endl;
  list.Get(1);
  list.Print();

  cout << "Get end: " << list.GetEnd() << endl;
  list.Print();

  cout << "Get end: " << list.GetEnd() << endl;
  list.Print();

  cout << "Get begin: " << list.GetBegin() << endl;
  list.Print();

  cout << "Get begin: " << list.GetBegin() << endl;
  try
  {
    list.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  cout << "\nTo put [end]: 873" << endl;
  list.PutEnd(873);
  list.Print();

  cout << "To put [begin]: 634" << endl;
  list.PutBegin(634);
  list.Print();

#endif
  TList <int> listOther(list);
  cout << "\n\nCopy constructor (adress of oldList: " << &list << ", adress of newList: " << &listOther << "): " << endl;
  listOther.Print();
  return 0;
}