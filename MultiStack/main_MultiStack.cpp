#include <iostream>
#include "MultiStack.h"

//Uncomment to use the stack I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with MultiStack."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;
  
  cout << "\nAttention. 0-based indexing is used." << endl;
  cout << "\nCreating MultiStack:" << endl;
  TMStack <int> multistack(12,3);
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= 4; j++)
    {
      multistack.Put(i, j);
      cout << "Elem " << j << " added to " << i << " stack." << endl;
    }
  multistack.Print();
  
  for (int i = 0; i < 2; i++)
    cout << "Get element " << multistack.Get(i) << " from " << i << " stack." << endl;
  multistack.Print();
  
  cout << "\nTry to repack and add elem '22' to 2 stack..." << endl;
  multistack.Put(2, 22);
  multistack.Print();
  
  TMStack <int> multistackOther(multistack);
  cout << "\nCopy constructor (adress of oldMStack: " << &multistack << ", adress of newMStack: " << &multistackOther << "): " << endl;
  cout << "Get element " << multistack.Get(1) << " from " << 1 << " stack of oldMStack." << endl;
  cout << "Get element " << multistackOther.Get(1) << " from " << 1 << " stack of newMStack." << endl;

  return 0;
}  