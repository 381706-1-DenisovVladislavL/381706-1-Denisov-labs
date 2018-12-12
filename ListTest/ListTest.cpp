#include "List.h"

#include <gtest.h>

//TEST(List, throws_when_create_list_with_negative_size)
//{
//  //ASSERT_ANY_THROW(TQueue <int> V(-1));
//}

TEST(List, get_end)
{
  TList <int> L;
  L.PutEnd(1);
  L.PutEnd(2);
  L.PutEnd(3);
  ASSERT_EQ(L.GetEnd(), 3);
  ASSERT_EQ(L.GetEnd(), 2);
  ASSERT_EQ(L.GetEnd(), 1);
}