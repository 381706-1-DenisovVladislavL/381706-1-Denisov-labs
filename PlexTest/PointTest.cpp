#include <gtest.h>
#include "../PlexLib/Point.h"

TEST(Point, can_create_point)
{
	ASSERT_NO_THROW(TPoint point);
}

TEST(Point, can_get_first_coordinate)
{
	TPoint point(1, 2);
	EXPECT_TRUE(1 == point.GetX());
}

TEST(Point, can_get_second_coordinate)
{
	TPoint point(1, 2);
	EXPECT_TRUE(2 == point.GetY());
}

TEST(Point, can_set_first_coordinate)
{
	TPoint point(1, 2);
	EXPECT_TRUE(1 == point.GetX());
	ASSERT_NO_THROW(point.SetX(3));
	EXPECT_TRUE(3 == point.GetX());
}

TEST(Point, can_set_second_coordinate)
{
	TPoint point(1, 2);
	EXPECT_TRUE(2 == point.GetY());
	ASSERT_NO_THROW(point.SetY(3));
	EXPECT_TRUE(3 == point.GetY());
}