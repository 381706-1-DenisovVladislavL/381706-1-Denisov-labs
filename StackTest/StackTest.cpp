#include "Stack.h"

#include <gtest.h>

TEST(Stack, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack <int> S(-1));
}

TEST(Stack, can_put_and_get) 
{
  TStack <int> S(1);
  S.Put(3);
  ASSERT_EQ(3,S.Get());
}

TEST(Stack, can_use_full_check_false)
{
  TStack <int> S(1);
  ASSERT_FALSE(S.IsFull());
}

TEST(Stack, can_use_full_check_true)
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_TRUE(S.IsFull());
}

TEST(Stack, can_use_empty_check_false) 
{
  TStack <int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(Stack, can_use_empty_check_true) 
{
  TStack <int> S(1);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, throws_when_in_full_stack_put_elem)
{
  TStack <int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(Stack, throws_when_from_empty_stack_get_elem)
{
  TStack <int> S(1);
  ASSERT_ANY_THROW(S.Get());
}