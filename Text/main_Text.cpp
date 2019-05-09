#include <iostream>
#include "../TextLib/Text.h"

//Uncomment to use the stack I/O example.
//#define __USE_EXAMPLE_IO__

using namespace std;

int main()
{
  cout << "An example of working with Text."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl;

  TText::SetNodeSize(10000);
 
#ifdef __USE_EXAMPLE_IO__
  char* str = new char[100];
  char* add = new char[20];
#endif
  int pos = 0, len = 0;

  cout << "\nEnter source Text: ";
#ifdef __USE_EXAMPLE_IO__
  fgets(str, 100, stdin);
#endif
#ifndef __USE_EXAMPLE_IO__
  char* str = "My text";
  cout << str << endl;
#endif
  TText text(str);
  cout << "Your Text is:" << endl;
  text.GetRoot()->Output();

  cout << "Enter the Text to be added: ";
#ifdef __USE_EXAMPLE_IO__
  fgets(add, 20, stdin);
#endif
#ifndef __USE_EXAMPLE_IO__
  char* add = "new";
  cout << add << endl;
#endif
  cout << "Enter the position where you want to add: ";
#ifdef __USE_EXAMPLE_IO__
  cin >> pos;
#endif
#ifndef __USE_EXAMPLE_IO__
  pos = 2;
  cout << pos << endl;
#endif
  text.Insert(pos, add);
  text.GetRoot()->Output();
  
  cout << "Enter the position after which the deletion will be made: ";
#ifdef __USE_EXAMPLE_IO__
  cin >> pos;
#endif
#ifndef __USE_EXAMPLE_IO__
  pos = 1;
  cout << pos << endl;
#endif
  cout << "Enter the number of items to delete: ";
#ifdef __USE_EXAMPLE_IO__
  cin >> len;
#endif
#ifndef __USE_EXAMPLE_IO__
  len = 2;
  cout << len << endl;
#endif
  text.Delete(pos, len);
  text.GetRoot()->Output();
  
  text.ClearMemory();

#ifdef __USE_EXAMPLE_IO__
  delete add;
  delete str;
#endif
  return 0;
}