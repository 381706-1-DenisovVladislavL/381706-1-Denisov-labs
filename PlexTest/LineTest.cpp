#include <gtest.h>
#include "../PlexLib/Line.h"

TEST(line, can_create_line_without_throw_1)
{
	ASSERT_NO_THROW(TLine line);
}

TEST(line, can_create_line_without_throw_2)
{
	TPoint point1(1, 1), point2(2, 2);
	ASSERT_NO_THROW(TLine line(&point1, &point2));
}

TEST(line, can_create_line_without_throw_3)
{
	ASSERT_NO_THROW(TLine line(1, 1, 2, 2));
}

TEST(line, can_use_copy_constructor)
{
	TPoint point1(1, 1), point2(2, 2);
	TLine line(&point1, &point2);
	ASSERT_NO_THROW(TLine copy(line));
}

TEST(line, can_set_X1_correct)
{
	TLine line;
	line.SetX1(1);
	EXPECT_EQ(line.GetX1(), 1);
}

TEST(line, can_set_Y1_correct)
{
	TLine line;
	line.SetY1(1);
	EXPECT_EQ(line.GetY1(), 1);
}

TEST(line, can_set_X2_correct)
{
	TLine line;
	line.SetX2(1);
	EXPECT_EQ(line.GetX2(), 1);
}

TEST(line, can_set_Y2_correct)
{
	TLine line;
	line.SetY2(1);
	EXPECT_EQ(line.GetY2(), 1);
}

TEST(line, can_set_point1_without_throws)
{
	TLine line;
	TPoint point(1, 1);
	ASSERT_NO_THROW(line.SetPoint1(&point));
}

TEST(line, can_set_point2_without_throws)
{
	TLine line;
	TPoint point(1, 1);
	ASSERT_NO_THROW(line.SetPoint2(&point));
}