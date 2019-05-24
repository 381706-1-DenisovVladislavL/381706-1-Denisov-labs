#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest.h>
#include "../HashTableLib/HashTableList.h"

TEST(HashTableList, can_create_hash_table_list_without_throws_1)
{
	ASSERT_NO_THROW(THashTableList<int> table);
}

TEST(HashTableList, can_create_hash_table_list_without_throws_2)
{
	ASSERT_NO_THROW(THashTableList<int> table(10));
}

TEST(HashTableList, can_add_element_to_hash_table_list_without_throws_1)
{
	THashTableList<int> table(10);
	string key = "key";
	TElemL<int> elem(key, 10);
	ASSERT_NO_THROW(table.Put(elem));
}

TEST(HashTableList, can_add_element_to_hash_table_list_correct_1)
{
	THashTableList<int> table(10);
	string key = "key";
	TElemL<int> elem(key, 10);
	table.Put(elem);
	EXPECT_EQ(table.Search(key) == elem, true);
}

TEST(HashTableList, can_add_element_to_hash_table_list_without_throws_2)
{
	THashTableList<int> table(10);
	string key = "key";
	ASSERT_NO_THROW(table.Put(key, 10, NULL));
}

TEST(HashTableList, can_add_element_to_hash_table_list_correct_2)
{
	THashTableList<int> table(10);
	string key = "key";
	TElemL<int> elem(key, 10);
	table.Put(key, 10, NULL);
	EXPECT_EQ(table.Search(key) == elem, true);
}

TEST(HashTableList, can_return_current_count_correct_0)
{
	THashTableList<int> table(10);
	EXPECT_EQ(table.GetCount(), 0);
}

TEST(HashTableList, can_delete_element_from_hash_table_list_without_throws)
{
	THashTableList<int> table(100);
	string key = "key";
	TElemL<int> elem(key, 10);
	table.Put(elem);
	ASSERT_NO_THROW(table.Del(key));
}

TEST(HashTableList, can_delete_element_from_hash_table_list_correct_1)
{
	THashTableList<int> table(10);
	string key = "key";
	TElemL<int> elem(key, 10);
	table.Put(elem);
	EXPECT_EQ(table.Del(key), true);
}

TEST(HashTableList, can_overcome_the_conflict)
{
	THashTableList<int> table(5);
	string key1 = "aa";
	string key2 = "Iy";
	TElemL<int> elem1(key1, 15);
	TElemL<int> elem2(key2, 20);
	table.Put(elem1);
	table.Put(elem2);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(HashTableList, can_overcome_the_conflict_correct)
{
	THashTableList<int> table(5);
	string key1 = "aa";
	string key2 = "Iy";
	TElemL<int> elem1(key1, 15);
	TElemL<int> elem2(key2, 20);
	table.Put(elem1);
	table.Put(elem2);
	EXPECT_EQ(table.Search(key1) == elem1, true);
	EXPECT_EQ(table.Search(key2) == elem2, true);
}

TEST(HashTableList, can_return_false_if_nomber_is_simple)
{
	THashTableList<int> table(10);
	EXPECT_EQ(table.IsSimple(15), false);
}

TEST(HashTableList, can_return_true_if_nomber_is_simple)
{
	THashTableList<int> table(10);
	EXPECT_EQ(table.IsSimple(7), true);
}