#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest.h>
#include "../HashTableLib/HashTable.h"

TEST(HashTable, can_create_hash_table_without_throws_1)
{
	ASSERT_NO_THROW(THashTable<int> table);
}

TEST(HashTable, can_create_hash_table_without_throws_2)
{
	ASSERT_NO_THROW(THashTable<int> table(10));
}

TEST(HashTable, can_add_element_to_hash_table_without_throws_1)
{
	THashTable<int> table(10);
	string key = "key";
	TElem<int> elem(key, 10);
	ASSERT_NO_THROW(table.Put(elem));
}

TEST(HashTable, can_add_element_to_hash_table_correct_1)
{
	THashTable<int> table(10);
	string key = "key";
	TElem<int> elem(key, 10);
	table.Put(elem);
	EXPECT_EQ(table.Search(key) == elem, true);
}

TEST(HashTable, can_add_element_to_hash_table_without_throws_2)
{
	THashTable<int> table(10);
	string key = "key";
	ASSERT_NO_THROW(table.Put(key, 10));
}

TEST(HashTable, can_add_element_to_hash_table_correct_2)
{
	THashTable<int> table(10);
	string key = "key";
	TElem<int> elem(key, 10);
	table.Put(key, 10);
	EXPECT_EQ(table.Search(key) == elem, true);
}

//TEST(HashTable, can_return_current_count_correct_0)
//{
//	THashTable<int> table(10);
//	EXPECT_EQ(table.GetCount(), 0);
//}
//
//TEST(HashTable, can_delete_element_from_hash_table_without_throws)
//{
//	THashTable<int> table(100);
//	string key = "key";
//	TElem<int> elem(key, 10);
//	table.Put(elem);
//	ASSERT_NO_THROW(table.Del(key));
//}
//
//TEST(HashTable, can_delete_element_from_hash_table_correct_1)
//{
//	THashTable<int> table(10);
//	string key = "key";
//	TElem<int> elem(key, 10);
//	table.Put(elem);
//	EXPECT_TRUE(table.Del(key));
//}
//
//TEST(HashTable, can_delete_element_from_hash_table_correct_2)
//{
//	THashTable<int> table(10);
//	string key = "key";
//	string key1 = "key1";
//	TElem<int> elem(key, 10);
//	table.Put(elem);
//	ASSERT_ANY_THROW(table.Del(key1));
//}
//
//TEST(HashTable, can_delete_element_from_hash_table_correct_0)
//{
//	THashTable<int> table(10);
//	string key = "key";
//	TElem<int> elem(key, 10);
//	table.Put(elem);
//	table.Del(key);
////	TElem<int> find = table.Search(key);
//	bool res = (table.Search(key) == table.GetNotFound());
//	EXPECT_EQ(res, true);
//}
//
//TEST(HashTable, can_overcome_the_conflict)
//{
//	THashTable<int> table(5);
//	string key1 = "aa";
//	string key2 = "Iy";
//	table.Put(key1, 15);
//	table.Put(key2, 20);
//	ASSERT_NO_THROW(table.Search(key2));
//}
//
//TEST(HashTable, can_overcome_the_conflict_correct)
//{
//	THashTable<int> table(5);
//	string key1 = "aa";
//	string key2 = "Iy";	
//	table.Put(key1, 15);	
//	table.Put(key2, 20);
//	TElem<int> elem(key2, 20);
//	bool res = (table.Search(key2) == elem);
//	EXPECT_EQ(res, true);
//}
//
//TEST(HashTable, can_return_false_if_nomber_is_simple)
//{
//	THashTable<int> table(10);
//	EXPECT_EQ(table.IsSimple(15), false);
//}
//
//TEST(HashTable, can_return_true_if_nomber_is_simple)
//{
//	THashTable<int> table(10);
//	EXPECT_EQ(table.IsSimple(7), true);
//}