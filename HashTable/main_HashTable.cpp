#include <iostream>
#include "HashTable.h"
#include "HashTableList.h"

using namespace std;

int main()
{
  cout << "An example of working with HashTable."
    << endl << "Denisov Vladislav L. Group 381706-1" << endl << endl;
  
  string key1 = "aa", key2 = "cb", key3 = "Iy";
  int data1 = 11, data2 = 22, data3 = 33;

  cout << "Create an empty hash table (conflict resolution by mixing)..." << endl;
  THashTable<int> tableArr;
  cout << tableArr << endl;

  cout << "Added to the table element with Key: 'aa', Data: '11'" << endl;
  tableArr.Put(key1, data1);
  cout << tableArr << endl;

  cout << "Added to the table element with Key: 'cb', Data: '22'" << endl;
  tableArr.Put(key2, data2);
  cout << tableArr << endl;

  cout << "Added to the table element with Key: 'Iy', Data: '33'" << endl;
  tableArr.Put(key3, data3);
  cout << tableArr << endl;

  cout << "Searching element with Key: 'aa'...\n";
  cout << "Found elem:  " << tableArr.Search(key1) << endl;

  cout << "\nDeleting element with key: 'aa'...\n";
  tableArr.Del(key1);
  cout << tableArr << endl;

  cout << "Searching element with key: 'aa'...\n";
  cout << "Found elem: " << tableArr.Search(key1) << endl;

  cout << "\n\n\n========================================="
	  << endl<< "An example of working with HashTableList." << endl << endl;

  cout << "Create an empty hash table (conflict resolution lists)..." << endl;
  THashTableList<int> tableList;
  cout << tableList << endl;
  
  cout << "Added to the table element with Key: 'aa', Data: '11'" << endl;
  TElemL<int> elem0("aa", 11);
  tableList.Put(elem0);
  cout << tableList << endl;

  cout << "Added to the table element with Key: 'bb', Data: '22'" << endl;
  TElemL<int> elem1("bb", 22);
  tableList.Put(elem1);
  cout << tableList << endl;

  cout << "Added to the table element with Key: 'Iy', Data: '33'" << endl;
  TElemL<int> elem2("Iy", 33);
  tableList.Put(elem2);
  cout << tableList << endl;

  cout << "Searching element with Key: 'aa'...\n";
  cout << "Found elem:  " << tableList.Search(key1) << endl;

  cout << "\nDeleting element with key: 'aa'...\n";
  tableList.Del(key1);
  cout << tableList << endl;

  cout << "Searching element with key: 'aa'...\n";
  cout << "Found elem: " << tableList.Search(key1) << endl;

  return 0;
}