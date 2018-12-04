#include "StackList.h"

#include <gtest.h>

TEST(StackList, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStackList <int> SL(-1));
}