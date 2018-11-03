#include "Vector.h"

#include <gtest.h>

TEST(Vector, throws_when_create_vector_with_negative_size)
{
	ASSERT_ANY_THROW(TVector <int> V(-1));
}

TEST(Vector, can_get_size)
{
	TVector <int> V(3);
	ASSERT_EQ(3, V.getSize());
}

TEST(Vector, thorws_when_index_argument_is_negative)
{
	TVector <int> V(3);
	ASSERT_ANY_THROW(V[-1]);
}

TEST(Vector, thorws_when_index_argument_more_or_eq_size)
{
	TVector <int> V(3);
	ASSERT_ANY_THROW(V[3]);
	ASSERT_ANY_THROW(V[4]);
}

TEST(Vector, can_use_index_operator) 
{
	TVector <int> V(3);
	V[1] = 3;
	int temp = V[1] + 1;
	ASSERT_EQ(4, temp);
}

TEST(Vector, can_compare_vectors_true) 
{
	TVector <int> V1(3), V2(3);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i;
		V2[i] = i;
	}
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_compare_vectors_false_with_one_size)
{
	TVector <int> V1(3), V2(3);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i;
		V2[i] = i + 1;
	}
	ASSERT_FALSE(V1 == V2);
}

TEST(Vector, can_compare_vectors_false_with_diff_size)
{
	TVector <int> V1(3), V2(5);
	ASSERT_FALSE(V1 == V2);
}

//TEST(Vector, can_assign_vector)
//{
//}
