#include <iostream>
#include "ScanTable.h"

using namespace std;

int main()
{
  cout << "An example of working with ScanTable."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl << endl;

  TTable<int> table(10);
  TElem<int> elem;

  cout << table << endl;

  cout << "Added to the table element with Key: 'key1', Data: '1'" << endl;
  table.Put("key1", 1);
  cout << "Added to the table element with Key: 'key2', Data: '3'" << endl;
  table.Put("key2", 3);
  cout << "Added to the table element with Key: 'key3', Data: '5'" << endl;
  table.Put("key3", 5);
  cout << "Added to the table element with Key: 'key4', Data: '7'" << endl;
  table.Put("key4", 7);
  cout << "Added to the table element with Key: 'key5', Data: '9'" << endl << endl;
  table.Put("key5", 9);

  cout << table;

  cout << "\nSearching element with Key: 'key4'...\n";
  elem = table.Search("key4");
  cout << "Found elem:  " << elem << endl;

  std::cout << "\nDeleting element with key: 'key4'...\n\n";
  table.Del("key4");
  cout << table;

  cout << "\nSearching element with key: 'key4'...\n";
  elem = table.Search("key4");
  cout << "Found elem: " << elem << endl;

  return 0;
}