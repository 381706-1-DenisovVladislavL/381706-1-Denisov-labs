#include "Queue.h"

#include <gtest.h>

TEST(Queue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue <int> V(-1));
}