#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "../TextLib/NodeIter.h"
#include <gtest.h>


TEST(NodeIter, can_create_iterator_without_throws)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	ASSERT_NO_THROW(TNodeIter iter(&text));
}

TEST(NodeIter, can_return_next_element_without_throws)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	ASSERT_NO_THROW(iter.GoNext());
}

TEST(NodeIter, can_return_next_element_1)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	EXPECT_EQ(iter.GoNext(), &text);
}

TEST(NodeIter, can_return_next_element_2)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	iter.GoNext();
	EXPECT_EQ(iter.GoNext(), &string);
}

TEST(NodeIter,can_reset_iterator_without_throws)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	iter.GoNext();
	ASSERT_NO_THROW(iter.Reset());
}

TEST(NodeIter, can_reset_iterator)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	iter.GoNext();
	iter.GoNext();
	iter.Reset();
	EXPECT_EQ(iter.GoNext(), &text);
}

TEST(NodeIter, can_isend_operator_without_throws)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	ASSERT_NO_THROW(iter.IsEnd());
}

TEST(NodeIter, can_isend_return_false_if_iterator_is_not_end)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	EXPECT_EQ(iter.IsEnd(), false);
}

TEST(NodeIter, can_isend_return_true_if_iterator_is_end)
{
	TNode text(0);
	TNode string(1);
	TNode word("Text");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	iter.GoNext();
	iter.GoNext();
	iter.GoNext();
	iter.GoNext();
	iter.GoNext();
	iter.GoNext();
	iter.GoNext(); 
	EXPECT_EQ(iter.IsEnd(), true);
}

TEST(NodeIter, can_use_current_operator_without_throws)
{
	TNode text(0);
	TNode string(1);
	TNode word("Hello");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	ASSERT_NO_THROW(iter());
}

TEST(NodeIter, can_return_curent_element)
{
	TNode text(0);
	TNode string(1);
	TNode word("Hello");
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNodeIter iter(&text);
	EXPECT_EQ(iter(), &text);
}
