#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, can_create_table)
{
	ASSERT_NO_THROW(TTable<int> table);
}

TEST(ScanTable, throw_when_create_table_with_negative_size)
{
	ASSERT_ANY_THROW(TTable<int> table(-1));
}

TEST(ScanTable, can_create_copy_table)
{
	TTable<int> table(5);
	ASSERT_NO_THROW(TTable<int> copy(table));
}

TEST(ScanTable, can_get_size_correct)
{
	TTable<int> table(5);
	EXPECT_EQ(5, table.GetSize());
}

TEST(ScanTable, can_get_count)
{
	TTable<int> table(5);
	EXPECT_EQ(0, table.GetCount());
	table.Put("my", 10);
	EXPECT_EQ(1, table.GetCount());
	table.Put("key", 12);
	EXPECT_EQ(2, table.GetCount());
}

TEST(ScanTable, can_put_elem_into_table)
{
	TTable<int> table(5);
	ASSERT_NO_THROW(table.Put("kluch", 10));
	EXPECT_EQ(1, table.GetCount());
}

TEST(ScanTable, throw_when_put_elem_into_table_but_table_is_full)
{
	TTable<int> table(1);
	table.Put("kluch1", 10);
	ASSERT_ANY_THROW(table.Put("kluch2", 11));
}

TEST(ScanTable, can_search_elem_in_table)
{
	TTable<int> table(5);
	TElem<int> elem;
	table.Put("key", 10);
	ASSERT_NO_THROW(elem = table.Search("key"));
	EXPECT_EQ("key", elem.GetKey());
	EXPECT_EQ(10, elem.GetData());
}

TEST(ScanTable, can_access_by_index)
{
	TTable<int> table(5);
	int tmp;
	table.Put("my", 10);
	ASSERT_NO_THROW(tmp = table["my"]);
	EXPECT_EQ(10, tmp);
	ASSERT_NO_THROW(table["my"] = 5);
	EXPECT_EQ(5, table["my"]);
}

TEST(ScanTable, can_delete_elem_from_table)
{
	TTable<int> table(5);
	table.Put("key", 10);
	ASSERT_NO_THROW(table.Del("key"));
}

TEST(ScanTable, throw_when_delete_elem_from_table_but_table_is_empty)
{
	TTable<int> table(5);
	ASSERT_ANY_THROW(table.Del("key"));
}