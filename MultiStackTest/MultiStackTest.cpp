#include "MultiStack.h"
#include <gtest.h>

//------------------------------------------
//Tests for NewStack

TEST(NewStack, throws_when_create_newstack_with_negative_size)
{
  int *ns = 0;
  ASSERT_ANY_THROW(TNewStack<int> newstack(-1, ns));
}

TEST(NewStack, can_create_newstack)
{
  int *ns = 0;
  ASSERT_NO_THROW(TNewStack<int> newstack(2, ns));
}

TEST(NewStack, can_use_copyconstructor_newstack)
{
  int *ns = 0;
  TNewStack<int> newstack(2, ns);
  ASSERT_NO_THROW(TNewStack<int> newstackcopy(newstack));
}

TEST(NewStack, can_get_free_mem)
{
  int *ns = new int[5];
  TNewStack<int> newstack(5, ns);
  newstack.Put(1);
  newstack.Put(2);
  ASSERT_EQ(3, newstack.CountFree());
}

TEST(NewStack, can_get_top)
{
  int *ns = new int[5];
  TNewStack<int> newstack(5, ns);
  newstack.Put(1);
  newstack.Put(2);
  ASSERT_EQ(2, newstack.GetTop());
}

TEST(NewStack, can_get_size)
{
  int *ns = 0;
  TNewStack<int> newstack(5, ns);
  ASSERT_EQ(5, newstack.GetSize());
}

TEST(NewStack, can_put_and_get_elem)
{
  int *ns = new int[5];
  TNewStack<int> newstack(5, ns);
  newstack.Put(1);
  newstack.Put(2);
  ASSERT_EQ(2, newstack.Get());
  ASSERT_EQ(1, newstack.Get());
}

//------------------------------------------
//Tests for MultiStack

TEST(MStack, can_create_mstack_with_positive_length)
{
  ASSERT_NO_THROW(TMStack<int> mstack(12, 3));
}

TEST(MStack, throws_when_create_mstack_with_negative_length)
{
  ASSERT_ANY_THROW(TMStack<int> mstack(-1, 3));
}

TEST(MStack, throws_when_create_mstack_with_negative_count_of_stacks)
{
  ASSERT_ANY_THROW(TMStack<int> mstack(10, 0));
}

TEST(MStack, can_use_copyconstructor_mstack)
{
  TMStack<int> mstack(12, 3);
  ASSERT_NO_THROW(TMStack<int> mstackcopy(mstack));
}

TEST(MStack, can_put_element)
{
  TMStack<int> mstack(12, 3);
  ASSERT_NO_THROW(mstack.Put(1, 2));
}

TEST(MStack, throws_when_put_element_in_full_mstack)
{
  TMStack<int> mstack(2, 2);
  mstack.Put(0, 1);
  mstack.Put(1, 2);
  ASSERT_ANY_THROW(mstack.Put(1, 3));
}

TEST(MStack, throws_when_put_element_in_negative_index)
{
  TMStack<int> mstack(12, 3);
  ASSERT_ANY_THROW(mstack.Put(-1, 3));
}

TEST(MStack, can_get_element)
{
  TMStack<int> mstack(12, 3);
  mstack.Put(1, 2);
  ASSERT_EQ(2, mstack.Get(1));
}

TEST(MStack, throws_when_get_element_from_negative_index)
{
  TMStack<int> mstack(12, 3);
  ASSERT_ANY_THROW(mstack.Get(-1));
}

TEST(MStack, throws_when_get_element_from_empty_mstack)
{
  TMStack<int> A(12, 3);
  ASSERT_ANY_THROW(A.Get(1));
}

TEST(MStack, can_repack)
{
  TMStack<int> mstack(6, 2);
  mstack.Put(0, 1);
  mstack.Put(0, 2);
  mstack.Put(0, 3);
  mstack.Put(1, 4);
  ASSERT_NO_THROW(mstack.Put(0, 5));
  ASSERT_EQ(5, mstack.Get(0));
}

TEST(MStack, correct_order_return_value)
{
  TMStack <int> mstack(6, 2);
  mstack.Put(1, 1);
  mstack.Put(1, 2);
  mstack.Put(1, 3);
  ASSERT_EQ(3, mstack.Get(1));
  ASSERT_EQ(2, mstack.Get(1));
  ASSERT_EQ(1, mstack.Get(1));
}

TEST(MStack, can_check_is_empty_true)
{
  TMStack<int> mstack(12, 3);
  ASSERT_TRUE(mstack.IsEmpty(1));
}

TEST(MStack, can_check_is_empty_false)
{
  TMStack<int> mstack(12, 3);
  mstack.Put(1, 1);
  ASSERT_FALSE(mstack.IsEmpty(1));
}

TEST(MStack, can_check_is_full_true)
{
  TMStack<int> mstack(12, 3);
  mstack.Put(1, 1);
  mstack.Put(1, 2);
  mstack.Put(1, 3);
  mstack.Put(1, 4);
  ASSERT_TRUE(mstack.IsFull(1));
}

TEST(MStack, can_check_is_full_false)
{
  TMStack<int> mstack(12, 3);
  mstack.Put(1, 1);
  mstack.Put(1, 2);
  mstack.Put(1, 3);
  ASSERT_FALSE(mstack.IsFull(1));
}

TEST(MStack, throw_when_check_is_full_or_empty_with_out_of_range_number)
{
  TMStack<int> mstack(12, 3);
  ASSERT_ANY_THROW(mstack.IsFull(3));
  ASSERT_ANY_THROW(mstack.IsEmpty(3));
  ASSERT_ANY_THROW(mstack.IsFull(-1));
  ASSERT_ANY_THROW(mstack.IsEmpty(-1));
}

//TEST(MStack, repack_extra_size_mstack) 
//{
//  TMStack<int> mstack(1000000, 10000);
//  for (int i = 0; i < 9000; i++)
//    for (int j = 1; j <= 70; j++)
//      mstack.Put(i, j);
//  for (int i = 9000; i < 10000; i++)
//    for (int j = 1; j <= 100; j++)
//      mstack.Put(i, j);
//  mstack.Put(9999, 101);
//  ASSERT_NO_THROW();
//}