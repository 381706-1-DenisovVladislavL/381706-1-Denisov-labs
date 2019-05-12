#include <gtest.h>
#include "../PlexLib/Plex.h"

TEST(Plex, can_create_plex_1)
{
	ASSERT_NO_THROW(TPlex plex);
}

TEST(Plex, can_create_plex_2) 
{
	TPoint *point1, *point2;
	point1 = new TPoint(1, 1);
	point2 = new TPoint(2, 2);
	ASSERT_NO_THROW(TPlex plex(point1, point2));
}

TEST(Plex, can_copy_plex)
{
	TPoint *point1, *point2;
	point1 = new TPoint(1, 1);
	point2 = new TPoint(2, 2);
	TPlex plex(point1, point2);
	ASSERT_NO_THROW(TPlex copy(plex));
}

TEST(Plex, can_add_line)
{
	TPlex plex;
	TPoint *a, *b;
	a = new TPoint(4, 4);
	b = new TPoint(3, 3);
	ASSERT_NO_THROW(plex.Add(a, b));
}

TEST(Plex, throw_when_add_error_line)
{
	TPlex plex;
	TPoint *a, *b, *c, *d;
	d = new TPoint(1, 1);
	b = new TPoint(3, 3);
	a = new TPoint(3, 4);
	c = new TPoint(4, 4);
	plex.Add(c, b);
	ASSERT_ANY_THROW(plex.Add(a, d));
}

TEST(Plex, can_get_first_point)
{
	TPlex plex;
	TPoint *a, *b;
	b = new TPoint(3, 3);
	a = new TPoint(4, 4);
	plex.Add(a, b);
	EXPECT_TRUE(a == plex.GetRight());
}

TEST(Plex, can_get_left_point)
{
	TPlex plex;
	TPoint *a, *b;
	b = new TPoint(3, 3);
	a = new TPoint(4, 4);
	plex.Add(a, b);
	EXPECT_TRUE(b == plex.GetLeft());
}

TEST(Plex, can_set_right_point)
{
	TPlex plex;
	TPoint *a, *b, *c;
	a = new TPoint(3, 3);
	b = new TPoint(4, 4);
	c = new TPoint(23, 4);
	plex.Add(a, b);
	EXPECT_TRUE(a == plex.GetRight());
	plex.SetRight(c);
	EXPECT_TRUE(c == plex.GetRight());
}

TEST(Plex, can_set_left_point)
{
	TPlex plex;
	TPoint *a, *b, *c;
	a = new TPoint(3, 3);
	b = new TPoint(4, 4);
	c = new TPoint(23, 4);
	plex.Add(a, b);
	EXPECT_TRUE(b == plex.GetLeft());
	plex.SetLeft(c);
	EXPECT_TRUE(c == plex.GetLeft());
}