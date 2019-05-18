#include <iostream>
#include "HashTable.h"
#include "HashTableList.h"

using namespace std;

int main()
{
  cout << "An example of working with HashTable."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl << endl;

  /*string* keys = new string[5];
  int* data = new int[5];
  keys[0] = "key2"; data[0] = 0;
  keys[1] = "key3"; data[1] = 1;
  keys[2] = "key1"; data[2] = 2;
  keys[3] = "key4"; data[3] = 3;
  keys[4] = "key0"; data[4] = 4;

  TElem<int> elem0("key0", 4);
  TElem<int> elem1("key1", 2);
  TElem<int> elem2("key2", 0);
  TElem<int> elem3("key3", 1);
  TElem<int> elem4("key4", 3);

  cout << "Arrays of 'Keys' and 'Data': " << endl;
  for (int i = 0; i < 5; i++)
	  cout << keys[i] << "\t" << data[i] << endl;
  cout << endl;

  cout << "Create a sorted table using 'Insert sorting'..." << endl;
  TSortTable<int> tableInsert(keys, data, 5, 0);
  tableInsert.Print();
  cout << endl;

  cout << "Create a sorted table using 'Shell sorting'..." << endl;
  TSortTable<int> tableShell(keys, data, 5, 1);
  tableShell.Print();
  cout << endl;

  cout << "Create a sorted table using 'Quick sorting'..." << endl;
  TSortTable<int> tableQuick(keys, data, 5, 2);
  tableQuick.Print();
  cout << endl;

  cout << "Create an empty sorted table..." << endl;
  TSortTable<int> table(1);
  table.Print(); 
  cout << endl;

  cout << "Added to the table element with Key: 'One1', Data: '1'" << endl;
  table.Put("One1", 1);
  table.Print();
  cout << endl;

  cout << "Added to the table element with Key: 'Two2', Data: '3'" << endl;
  table.Put("Two2", 3);
  table.Print();
  cout << endl;

  cout << "Added to the table element with Key: 'Three3', Data: '5'" << endl;
  table.Put("Three3", 5);
  table.Print();

  TElem<int> elem;
  cout << "Searching element with Key: 'Two2'...\n";
  elem = table.Search("Two2");
  cout << "Found elem:  " << elem << endl;

  std::cout << "\nDeleting element with key: 'Two2'...\n\n";
  table.Del("Two2");
  table.Print();

  cout << "\nSearching element with key: 'Two2'...\n";
  elem = table.Search("Two2");
  cout << "Found elem: " << elem << endl;*/

  cout << "====================================="
	  << endl << "An example of working with HashTableList." << endl << endl;

  THashTableList<int> table(5);
  cout << table << endl;
  cout << "Added to the table element with Key: 'aa', Data: '11'" << endl;
  TElemL<int> elem0("aa", 11);
  cout << elem0 << endl;
  table.Put(elem0);
  cout << table << endl;

  cout << "Added to the table element with Key: 'bb', Data: '22'" << endl;
  TElemL<int> elem1("bb", 22);
  cout << elem1 << endl;
  table.Put(elem1);
  cout << table << endl;

  cout << "Added to the table element with Key: 'Iy', Data: '33'" << endl;
  TElemL<int> elem2("Iy", 33);
  cout << elem2 << endl;
  table.Put(elem2);
  cout << table << endl;

  table.Del("aa");
  cout << table << endl;

  return 0;
}