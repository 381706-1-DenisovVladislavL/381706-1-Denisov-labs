#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "Queue.h"

#include <gtest.h>

TEST(Queue, throws_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue <int> V(-1));
}

TEST(Queue, can_put_and_get)
{
  TQueue <int> Q(1);
  Q.Put(3);
  ASSERT_EQ(3, Q.Get());
}

TEST(Queue, can_use_full_check_false)
{
  TQueue <int> Q(1);
  ASSERT_FALSE(Q.IsFull());
}

TEST(Queue, can_use_full_check_true)
{
  TQueue <int> Q(1);
  Q.Put(5);
  ASSERT_TRUE(Q.IsFull());
}

TEST(Queue, can_use_empty_check_false)
{
  TQueue <int> Q(1);
  Q.Put(5);
  ASSERT_FALSE(Q.IsEmpty());
}

TEST(Queue, can_use_empty_check_true)
{
  TQueue <int> Q(1);
  ASSERT_TRUE(Q.IsEmpty());
}

TEST(Queue, check_circular_put_in_queue) 
{
  TQueue <int> Q(3);
  Q.Put(1); // 1 > exit
  Q.Put(2); // 2 1
  Q.Put(3); // 3 2 1
  Q.Get(); // 3 2
  Q.Get(); // 3
  Q.Put(4); // 4 3
  Q.Put(5); // 5 4 3
  Q.Get(); // 5 4
  ASSERT_EQ(4, Q.Get());
}