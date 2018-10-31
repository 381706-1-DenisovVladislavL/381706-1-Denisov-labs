#include "Vector.h"

#include <gtest.h>

TEST(Vector, throws_when_create_vector_with_negative_size)
{
	ASSERT_ANY_THROW(TVector <int> V(-1));
}