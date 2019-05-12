#include <gtest.h>
#include "Circle.h"

TEST(Circle, can_create_circle_without_throws_1)
{
	ASSERT_NO_THROW(TCircle circle);
}

TEST(Circle, can_create_circle_without_throws_2)
{
	TPoint point(1, 1);
	ASSERT_NO_THROW(TCircle circle(&point, 1));
}

TEST(Circle, can_throw_when_create_circle_with_negative_radius_1)
{
	TPoint point(1, 1);
	ASSERT_ANY_THROW(TCircle circle(&point, -1));
}

TEST(Circle, can_create_circle_without_throws_3)
{
	ASSERT_NO_THROW(TCircle circle(1, 1, 1));
}

TEST(Circle, can_throw_when_create_circle_with_negative_radius_2)
{
	ASSERT_ANY_THROW(TCircle circle(1, 1, -1));
}

TEST(Circle, can_use_copy_constructor)
{
	TCircle circle(1, 1, 1);
	ASSERT_NO_THROW(TCircle copy(circle));
}

TEST(Circle, can_get_X_correct)
{
	TCircle circle(1, 2, 3);
	EXPECT_EQ(circle.GetX(), 1);
}

TEST(Circle, can_get_Y_correct)
{
	TCircle circle(1, 2, 3);
	EXPECT_EQ(circle.GetY(), 2);
}

TEST(Circle, can_get_radius_correct)
{
	TCircle circle(1, 2, 3);
	EXPECT_EQ(circle.GetRadius(), 3);
}

TEST(Circle, can_throw_if_set_negative_radius)
{
	TCircle circle(1, 1, 1);
	ASSERT_ANY_THROW(circle.SetRadius(-1));
}

TEST(Circle, can_set_X_correct)
{
	TCircle circle(1, 1, 1);
	circle.SetX(2);
	EXPECT_EQ(circle.GetX(), 2);
}

TEST(Circle, can_set_Y_correct)
{
	TCircle circle(1, 1, 1);
	circle.SetY(2);
	EXPECT_EQ(circle.GetY(), 2);
}

TEST(Circle, can_set_Radius_correct)
{
	TCircle circle(1, 1, 1);
	circle.SetRadius(2);
	EXPECT_EQ(circle.GetRadius(), 2);
}