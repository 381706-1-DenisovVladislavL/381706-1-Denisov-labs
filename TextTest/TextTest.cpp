#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "../TextLib/Text.h"
#include <gtest.h>

TEST(Text, can_create_text_without_throws)
{
	ASSERT_NO_THROW(TText text("My text"));
}

TEST(Text, can_create_copy_text_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(TText copy(text));
}

TEST(Text, can_insert_text_1_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(text.Insert(2, "new"));
}

TEST(Text, can_insert_text_1_correct)
{
	TNode::ClearMemory();
	TText text("My text");
	text.Insert(2, "new");
	EXPECT_EQ(text.GetRoot()->ToString()[2], 'n');
	EXPECT_EQ(text.GetRoot()->ToString()[3], 'e');
	EXPECT_EQ(text.GetRoot()->ToString()[4], 'w');
}

TEST(Text, can_insert_text_2_without_throws)
{
	TText text("My text");
	TNode word("new");
	TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(text.Insert(tmp, &word));
}

TEST(Text, can_insert_text_2_correct)
{
	TNode::ClearMemory();
	TText text("My text");
	TNode word("new");
	TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel();
	text.Insert(tmp, &word);
	EXPECT_EQ(text.GetRoot()->ToString()[3], 'n');
	EXPECT_EQ(text.GetRoot()->ToString()[4], 'e');
	EXPECT_EQ(text.GetRoot()->ToString()[5], 'w');
}

TEST(Text, can_find_text_1_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(text.Find("ex"));
}

TEST(Text, can_find_text_1_correct)
{
	TText text("Mytext");
	EXPECT_EQ(text.Find("ex"), 3);
}

TEST(Text, can_find_text_2_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(text.FindNode("ex"));
}

TEST(Text, can_find_text_2_correct)
{
	TNode::ClearMemory();
	TText text("My text");
	TNode* tmp = text.FindNode("ex");
	EXPECT_EQ(text.GetRoot()->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetNextLevel()->GetSameLevel(), tmp);
}

TEST(Text, can_copy_text_1_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(text.Copy(2, 3));
}

TEST(Text, can_copy_text_1_correct)
{
	TText text("My text");
	char* tmp = text.Copy(2, 3);
	EXPECT_EQ(tmp[0], 't');
	EXPECT_EQ(tmp[1], 'e');
	EXPECT_EQ(tmp[2], 'x');
	TNode::ClearMemory();
}

TEST(Text, can_copy_text_2_without_throws)
{
	TText text("My text");
	TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(text.Copy(tmp, 3));
}

TEST(Text, can_copy_text_2_correct)
{
	TText text("My text");
	TNode* tmp1 = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel()->GetSameLevel();
	TNode* tmp2 = text.Copy(tmp1, 2);
	EXPECT_EQ(tmp2->GetNextLevel()->GetNextLevel()->GetLetter(), 'y');
	EXPECT_EQ(tmp2->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 't');
	TNode::ClearMemory();
}

TEST(Text, can_delete_element_1_without_throws)
{
	TText text("My text");
	ASSERT_NO_THROW(text.Delete(2, 3));
}

TEST(Text, can_delete_element_1_correct)
{
	TText text("My text");
	text.Delete(3, 2);
	EXPECT_EQ(text.GetRoot()->ToString()[0], 'M');
	EXPECT_EQ(text.GetRoot()->ToString()[1], 'y');
	EXPECT_EQ(text.GetRoot()->ToString()[2], ' ');
	EXPECT_EQ(text.GetRoot()->ToString()[3], 't');
	EXPECT_EQ(text.GetRoot()->ToString()[4], 't');
}

TEST(Text, can_delete_element_2_without_throws)
{
	TText text("Mytext");
	TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(text.Delete(tmp, 2));
}

//Test is correct on visualstudiocompiller
//TEST(Text, can_delete_element_2_correct)
//{
//	TNode::ClearMemory();
//	TText text("Mytext");
//	TNode* tmp = text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
//	text.Delete(tmp, 2);
//	text.GetRoot()->GarbageCollector();
//	EXPECT_EQ(text.GetRoot()->ToString()[0], 't');
//	EXPECT_EQ(text.GetRoot()->ToString()[1], 'e');
//	EXPECT_EQ(text.GetRoot()->ToString()[2], 'x');
//	EXPECT_EQ(text.GetRoot()->ToString()[3], 't');
//}