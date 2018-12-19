#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "StackList.h"
#include <gtest.h>

TEST(StackList, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList <int> S(-1));
}

TEST(StackList, can_put_and_get)
{
  TStackList <int> S(1);
  S.Put(3);
  ASSERT_EQ(3, S.Get());
}

TEST(StackList, correct_order_return_value)
{
  TStackList <int> S(3);
  S.Put(1);
  S.Put(2);
  S.Put(3);
  ASSERT_EQ(3, S.Get());
  ASSERT_EQ(2, S.Get());
  ASSERT_EQ(1, S.Get());
}

TEST(StackList, can_use_full_check_false)
{
  TStackList <int> S(1);
  ASSERT_FALSE(S.IsFull());
}

TEST(StackList, can_use_full_check_true)
{
  TStackList <int> S(1);
  S.Put(5);
  ASSERT_TRUE(S.IsFull());
}

TEST(StackList, can_use_empty_check_false)
{
  TStackList <int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(StackList, can_use_empty_check_true)
{
  TStackList <int> S(1);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(StackList, throws_when_in_full_stack_put_elem)
{
  TStackList <int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(StackList, throws_when_from_empty_stack_get_elem)
{
  TStackList <int> S(1);
  ASSERT_ANY_THROW(S.Get());
}