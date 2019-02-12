#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest.h>
#include "List.h"

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(TList<int> lost);
}

TEST(List, can_create_copy_of_the_list)
{
  TList<int> otherlist;
  ASSERT_NO_THROW(TList<int> list(otherlist));
}

TEST(List, can_put_begin)
{
  TList<int> list;
  ASSERT_NO_THROW(list.PutBegin(10));
}

TEST(List, can_put_end)
{
  TList<int> list;
  ASSERT_NO_THROW(list.PutEnd(10));
}

TEST(List, can_get_begin)
{
  TList<int> list;
  list.PutBegin(10);
  list.PutBegin(20);
  ASSERT_EQ(20,list.GetBegin());
}

TEST(List, can_get_end)
{
  TList<int> list;
  list.PutBegin(10);
  list.PutBegin(20);
  ASSERT_EQ(10,list.GetEnd());
}

TEST(List, throws_when_get_begin_from_empty_list)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetBegin());
}

TEST(List, throws_when_get_end_from_empty_list)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(List, can_use_empty_check_true)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(List, can_use_empty_check_false)
{
  TList<int> list;
  list.PutBegin(1);
  ASSERT_FALSE(list.IsEmpty());
}

/*TEST(List, can_check_full_true)
{
  TList<int> list;
  try
  {
    while (1)
      list.PutBegin(1);
  }
  catch (...)
  {
    ASSERT_TRUE(list.IsFull());
  }
}*/

TEST(List, throw_get_elem_to_index_when_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.Get(1));
}

TEST(List, throw_get_elem_to_incorrent_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);
  ASSERT_ANY_THROW(list.Get(0));
  ASSERT_ANY_THROW(list.Get(3));
}

TEST(List, can_get_elem_to_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);
  ASSERT_EQ(list.Get(1), 2);
}

TEST(List, throw_put_elem_to_incorrent_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);
  ASSERT_ANY_THROW(list.Put(0, 1));
  ASSERT_ANY_THROW(list.Put(3, 1));
}

TEST(List, can_put_elem_to_index)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  list.Put(1, 10);
  ASSERT_EQ(list.Get(1), 10);
  ASSERT_EQ(list.Get(1), 2);
}