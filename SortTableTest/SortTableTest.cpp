#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest.h>
#include "SortTable.h"

TEST(SortTable, can_create_sort_table_without_throws)
{
	ASSERT_NO_THROW(TSortTable<int> table);
}

TEST(SortTable, can_creaate_sort_table_with_some_size_without_throws)
{
	ASSERT_NO_THROW(TSortTable<int> table(10));
}

TEST(SortTable, can_add_element_to_sort_table_without_throws)
{
	TSortTable<int> table(10);
	string key = "key";
	table.Put(key, 10);
}

TEST(SortTable, can_add_element_to_sort_table_correct_pos)
{
	TSortTable<int> table(5);
	string key = "key";
	EXPECT_EQ(table.Put(key, 10), 0);
}

TEST(SortTable, can_add_element_to_sort_table_with_resize_without_throws)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	string key3 = "key3";
	table.Put(key1, 10);
	table.Put(key2, 20);
	ASSERT_NO_THROW(table.Put(key3, 30));
}

TEST(SortTable, can_add_element_to_sort_table_with_resize_correct_pos)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	string key3 = "key3";
	table.Put(key1, 10);
	table.Put(key2, 20);
	EXPECT_EQ(table.Put(key3, 30), 2);
}

TEST(SortTable, can_add_element_to_sort_table_correct_data)
{
	TSortTable<int> table(5);
	string key = "key";
	table.Put(key, 10);
	EXPECT_EQ(table[key], 10);
}

TEST(SortTable, can_search_element_to_sort_table_without_throws_1)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	table.Put(key1, 10);
	table.Put(key2, 20);
	ASSERT_NO_THROW(table.Search(key1));
}

TEST(SortTable, can_search_element_to_sort_table_without_throws_2)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	string key3 = "key3";
	table.Put(key1, 10);
	table.Put(key2, 20);
	table.Put(key3, 30);
	ASSERT_NO_THROW(table.Search(key2));
}

TEST(SortTable, can_search_element_to_sort_table_correct)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	string key3 = "key3";
	table.Put(key1, 10);
	table.Put(key2, 20);
	table.Put(key3, 30);
	TElem<int> elem(key2, 20);
	EXPECT_EQ(table.Search(key2) == elem, 1);
}

TEST(SortTable, cad_delete_element_in_sort_table_without_throws)
{
	TSortTable<int> table(2);
	string key1 = "key1";
	string key2 = "key2";
	string key3 = "key3";
	table.Put(key1, 10);
	table.Put(key2, 20);
	table.Put(key3, 30);
	ASSERT_NO_THROW(table.Del(key2));
}

TEST(SortTable, can_create_table_with_sort_by_insert_sort_without_throws)
{
	string* keys = new string[5];
	keys[0] = "key0"; keys[1] = "key1"; keys[2] = "key2";
	keys[3] = "key3"; keys[4] = "key4";

	int* data = new int[5];
	data[0] = 0; data[1] = 1; data[2] = 2;
	data[3] = 3; data[4] = 4;

	ASSERT_NO_THROW(TSortTable<int> table(keys, data, 5, 0));
}

TEST(SortTable, can_create_table_with_sort_seetable_by_insert_sort_correct)
{
	string* keys = new string[5];
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

	TSortTable<int> table(keys, data, 5, 0);
	
	EXPECT_EQ(table.Search("key0") == elem0, 1);
	EXPECT_EQ(table.Search("key1") == elem1, 1);
	EXPECT_EQ(table.Search("key2") == elem2, 1);
	EXPECT_EQ(table.Search("key3") == elem3, 1);
	EXPECT_EQ(table.Search("key4") == elem4, 1);
}

TEST(SortTable, can_create_table_with_sort_shell_sort_without_throws)
{
	string* keys = new string[5];
	keys[0] = "key0"; keys[1] = "key1"; keys[2] = "key2";
	keys[3] = "key3"; keys[4] = "key4";

	int* data = new int[5];
	data[0] = 0; data[1] = 1; data[2] = 2;
	data[3] = 3; data[4] = 4;

	ASSERT_NO_THROW(TSortTable<int> table(keys, data, 5, 1));
}

TEST(SortTable, can_create_table_with_sort_by_shell_sort_correct)
{
	string* keys = new string[5];
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

	TSortTable<int> table(keys, data, 5, 1);

	EXPECT_EQ(table.Search("key0") == elem0, 1);
	EXPECT_EQ(table.Search("key1") == elem1, 1);
	EXPECT_EQ(table.Search("key2") == elem2, 1);
	EXPECT_EQ(table.Search("key3") == elem3, 1);
	EXPECT_EQ(table.Search("key4") == elem4, 1);
}

TEST(SortTable, can_create_table_with_sort_by_quick_sort_without_throws)
{
	string* keys = new string[5];
	keys[0] = "key0"; keys[1] = "key1"; keys[2] = "key2";
	keys[3] = "key3"; keys[4] = "key4";

	int* data = new int[5];
	data[0] = 0; data[1] = 1; data[2] = 2;
	data[3] = 3; data[4] = 4;

	ASSERT_NO_THROW(TSortTable<int> table(keys, data, 5, 2));
}

TEST(SortTable, can_create_table_with_sort_by_quick_sort_correct)
{
	string* keys = new string[5];
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

	TSortTable<int> table(keys, data, 5, 2);

	EXPECT_EQ(table.Search("key0") == elem0, 1);
	EXPECT_EQ(table.Search("key1") == elem1, 1);
	EXPECT_EQ(table.Search("key2") == elem2, 1);
	EXPECT_EQ(table.Search("key3") == elem3, 1);
	EXPECT_EQ(table.Search("key4") == elem4, 1);
}