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

TEST(Vector, can_assign_vector)
{
	TVector <int> V1(3), V2(5);
	V1 = V2;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_prefix_increment)
{
	TVector <int> V1(2), V2(2);
	V2 = V1++;
	ASSERT_FALSE(V1 == V2);
	V2[0] = V2[0] + 1;
	V2[1] = V2[1] + 1;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_postfix_increment)
{
	TVector <int> V1(2), V2(2);
	V2 = ++V1;
	ASSERT_TRUE(V1 == V2);
	V2[0] = V2[0] - 1;
	V2[1] = V2[1] - 1;
	ASSERT_FALSE(V1 == V2);
}

TEST(Vector, can_prefix_decrement)
{
	TVector <int> V1(2), V2(2);
	V2 = V1--;
	ASSERT_FALSE(V1 == V2);
	V2[0] = V2[0] - 1;
	V2[1] = V2[1] - 1;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_postfix_decrement)
{
	TVector <int> V1(2), V2(2);
	V2 = --V1;
	ASSERT_TRUE(V1 == V2);
	V2[0] = V2[0] - 1;
	V2[1] = V2[1] - 1;
	ASSERT_FALSE(V1 == V2);
}

TEST(Vector, can_unary_addition)
{
	TVector <int> V1(2), V2(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i + 1;
		V2[i] = i + 1;
	}
	V1 = +V1;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_unary_subtraction)
{
	TVector <int> V1(2), V2(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i + 1;
		V2[i] = -(i + 1);
	}
	V1 = -V1;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_addition_vectors)
{
	TVector <int> V1(2), V2(2), Temp(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i;
		V2[i] = i + 1;
		Temp[i] = V1[i] + V2[i];
	}
	ASSERT_TRUE(Temp == (V1 + V2));
}

TEST(Vector, thorws_when_addition_vectors_with_diff_size) 
{
	TVector <int> V1(2), V2(3);
	ASSERT_ANY_THROW(V1 + V2);
}

TEST(Vector, can_subtraction_vectors)
{
	TVector <int> V1(2), V2(2), Temp(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i;
		V2[i] = i + 1;
		Temp[i] = V1[i] - V2[i];
	}
	ASSERT_TRUE(Temp == (V1 - V2));
}

TEST(Vector, thorws_when_subtraction_vectors_with_diff_size)
{
	TVector <int> V1(2), V2(3);
	ASSERT_ANY_THROW(V1 - V2);
}

TEST(Vector, can_multiplication_vectors) 
{
	TVector <int> V1(2), V2(2);
	int temp = 0;
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = i;
		V2[i] = i + 1;
		temp += i * (i + 1);
	}
	ASSERT_EQ(temp,V1*V2);
}

TEST(Vector, throws_when_multiplication_vectors_with_diff_size)
{
	TVector <int> V1(2), V2(3);
	ASSERT_ANY_THROW(V1*V2);
}

TEST(Vector, can_multiplication_vector_by_number) 
{
	TVector <int> V1(2), V2(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = (i + 1);
		V2[i] = 2 * (i + 1);
	}
	V1 = V1 * 2;
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_multiplication_number_by_vector)
{
	TVector <int> V1(2), V2(2);
	for (int i = 0; i < V1.getSize(); i++) {
		V1[i] = (i + 1);
		V2[i] = 2 * (i + 1);
	}
	V1 = 2 * V1;
	ASSERT_TRUE(V1 == V2);
}