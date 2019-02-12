#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "StackList.h"
#include <gtest.h>

TEST(StackList, can_put_and_get)
{
  TStackList <int> S;
  S.Put(3);
  ASSERT_EQ(3, S.Get());
}

TEST(StackList, correct_order_return_value)
{
  TStackList <int> S;
  S.Put(1);
  S.Put(2);
  S.Put(3);
  ASSERT_EQ(3, S.Get());
  ASSERT_EQ(2, S.Get());
  ASSERT_EQ(1, S.Get());
}

/*TEST(StackList, throws_when_in_full_stack_put_elem)
{
  TStackList <int> s;
  try
  {
    while (1)
      s.Put(1);
  }
  catch (...)
  {
    ASSERT_ANY_THROW(s.Put(1));
  }
} */

TEST(StackList, throws_when_from_empty_stack_get_elem)
{
  TStackList <int> S;
  ASSERT_ANY_THROW(S.Get());
}