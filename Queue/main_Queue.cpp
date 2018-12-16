#include <iostream>
#include "Queue.h"

//Uncomment to use the stack I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with Queue."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  cout << "\nEnter the number of elements in the queue: ";
  try
  {
    int n = 3;
#ifdef __USE_EXAMPLE_IO__
    cin >> n;
#endif
#ifndef __USE_EXAMPLE_IO__
    cout << n << endl;
#endif

    TQueue <int> queue(n);
    cout << "Enter the elements of the queue: \n";
    for (int i = 0; i < n; i++)
    {
      int k;
#ifdef __USE_EXAMPLE_IO__
      cin >> k;
#endif
#ifndef __USE_EXAMPLE_IO__
      k = i + 1;
      cout << k << " ";
#endif
      queue.Put(k);
    }
    queue.Print();

    cout << "\n\nGet the element of the queue: " << queue.Get();
    queue.Print();

    cout << "\nEnter the element of the queue: ";
    int r = 4;
#ifdef __USE_EXAMPLE_IO__
    cin >> r;
#endif
#ifndef __USE_EXAMPLE_IO__
    cout << r;
#endif
    queue.Put(r);
    queue.Print();

    TQueue <int> queueOther(queue);
    cout << "\n\nCopy constructor (adress of oldQueue: " << &queue << ", adress of newQueue: " << &queueOther << "): ";
    queueOther.Print();
  }
  catch (TException exp)
  {
    exp.Print();
  }
  return 0;
}