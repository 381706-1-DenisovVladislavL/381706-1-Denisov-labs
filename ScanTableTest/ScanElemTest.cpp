#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest.h>
#include "ScanElem.h"

TEST(Elem, can_create_elem)
{
	ASSERT_NO_THROW(TElem<int>("key", 10));
}

TEST(Elem, can_create_copy_elem)
{
	TElem<int> elem("key", 10);
	ASSERT_NO_THROW(TElem<int> copy(elem));
}

TEST(Elem, can_set_and_get_key)
{
	string key = "newkey";
	TElem<int> elem;
	ASSERT_NO_THROW(elem.SetKey(key));
	EXPECT_EQ(key, elem.GetKey());
}

TEST(Elem, can_set_and_get_data)
{
	TElem<int> elem;
	ASSERT_NO_THROW(elem.SetData(10));
	EXPECT_EQ(10, elem.GetData());
}

TEST(Elem, can_compare_two_elems)
{
	TElem<int> elem1("key", 10);
	TElem<int> elem2("key", 10);
	TElem<int> elem3("otherkey", 10);
	TElem<int> elem4("key", 5);
	ASSERT_TRUE(elem1 == elem2);
	ASSERT_FALSE(elem1 == elem3);
	ASSERT_FALSE(elem1 == elem4);
	ASSERT_TRUE(elem1 != elem3);
}

TEST(Elem, can_assign_elem)
{
	TElem<int> elem1("key", 10);
	TElem<int> elem2;
	ASSERT_NO_THROW(elem2 = elem1);
	EXPECT_EQ("key", elem2.GetKey());
	EXPECT_EQ(10, elem2.GetData());
}