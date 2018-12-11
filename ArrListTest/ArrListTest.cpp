#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list_with_not_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> L());
}

TEST(ArrList, can_create_list_with_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> L(3));
}

TEST(ArrList, throws_when_create_list_with_size_eq_zero)
{
  ASSERT_ANY_THROW(TArrList <int> L(0));
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> L(-1));
}

TEST(ArrList, can_push_and_pull_start)
{
  TArrList <int> L(2);
  L.PushStart(1);
  L.PushStart(2);
  ASSERT_EQ(2, L.PullStart());
  ASSERT_EQ(1, L.PullStart());
}

TEST(ArrList, can_push_and_pull_finish)
{
  TArrList <int> L(2);
  L.PushFinish(1);
  L.PushFinish(2);
  ASSERT_EQ(2, L.PullFinish());
  ASSERT_EQ(1, L.PullFinish());
}

TEST(ArrList, can_use_full_check_false)
{
  TArrList <int> L(1);
  ASSERT_FALSE(L.IsFull());
}

TEST(ArrList, can_use_full_check_true)
{
  TArrList <int> L(1);
  L.PushStart(5);
  ASSERT_TRUE(L.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
  TArrList <int> L(1);
  L.PushStart(5);
  ASSERT_FALSE(L.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
  TArrList <int> L(1);
  ASSERT_TRUE(L.IsEmpty());
}

TEST(ArrList, throws_when_in_full_list_push_start_elem)
{
  TArrList <int> L(1);
  L.PushStart(1);
  ASSERT_ANY_THROW(L.PushStart(2));
}

TEST(ArrList, throws_when_in_full_list_push_finish_elem)
{
  TArrList <int> L(1);
  L.PushStart(1);
  ASSERT_ANY_THROW(L.PushFinish(2));
}

TEST(ArrList, throws_when_in_empty_list_pull_start_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.PullStart());
}

TEST(ArrList, throws_when_in_empty_list_pull_finish_elem)
{
  TArrList <int> L(1);
  ASSERT_ANY_THROW(L.PullFinish());
}

TEST(ArrList, can_use_queue_free_elements)
{
  TArrList <int> L(5);
  L.PushStart(1); //1
  L.PushStart(2); //2 1
  L.PushFinish(3); //2 1 3
  ASSERT_EQ(2, L.PullStart()); //1 3
  L.PushStart(4); //4 1 3
  L.PushStart(5); //5 4 1 3
  ASSERT_EQ(3, L.PullFinish()); //5 4 1
  ASSERT_EQ(1, L.PullFinish()); //5 4
  ASSERT_EQ(4, L.PullFinish()); //5
  L.PushFinish(6); //5 6
  ASSERT_EQ(5, L.PullStart()); //6
}