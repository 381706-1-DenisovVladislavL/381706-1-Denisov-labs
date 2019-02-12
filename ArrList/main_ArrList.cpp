#include <iostream>
#include "ArrList.h"

//Uncomment to use the arrlist I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with ArrList."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  TArrList <int> list;
#ifdef __USE_EXAMPLE_IO__
  int elem;

  cout << "\nEnter the elements of the ArrList: \n";
  cout << "To put [begin]: ";
  cin >> elem;
  list.PushStart(elem);

  cout << "To put [end]: ";
  cin >> elem;
  list.PushFinish(elem);

  cout << "To put [begin]: ";
  cin >> elem;
  list.PushStart(elem);

  cout << "To put [end]: ";
  cin >> elem;
  list.PushFinish(elem);

  cout << "Get end: " << list.PullFinish() << endl;

  cout << "Get end: " << list.PullFinish() << endl;

  cout << "Get begin: " << list.PullStart() << endl;

  cout << "Get begin: " << list.PullStart() << endl;

  cout << "\nTo put [end]: ";
  cin >> elem;
  list.PushFinish(elem);

  cout << "To put [begin]: ";
  cin >> elem;
  list.PushStart(elem);
#endif 
#ifndef __USE_EXAMPLE_IO__
  cout << "\nEnter the elements of the List: \n";
  cout << "To put [begin]: 5" << endl;
  list.PushStart(5);

  cout << "To put [end]: 34" << endl;
  list.PushFinish(34);

  cout << "To put [begin]: 123" << endl;
  list.PushStart(123);

  cout << "To put [end]: 992" << endl;
  list.PushFinish(992);

  cout << "Get end: " << list.PullFinish() << endl;

  cout << "Get end: " << list.PullFinish() << endl;

  cout << "Get begin: " << list.PullStart() << endl;

  cout << "Get begin: " << list.PullStart() << endl;

  cout << "\nTo put [end]: 873" << endl;
  list.PushFinish(873);

  cout << "To put [begin]: 634" << endl;
  list.PushStart(634);
#endif
  TArrList<int> listOther(list);
  cout << "\n\nCopy constructor (adress of oldList: " << &list << ", adress of newList: " << &listOther << "): " << endl;

  cout << "[oldList] Get begin: " << list.PullStart() << endl;
  cout << "[oldList] Get end: " << list.PullFinish() << endl;
  
  cout << "[newList] Get begin: " << listOther.PullStart() << endl;
  cout << "[newList] Get begin: " << listOther.PullStart() << endl;

  return 0;
}