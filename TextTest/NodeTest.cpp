#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "../TextLib/Node.h"
#include <gtest.h>

TEST(Node, can_create_node_with_zero_level)
{
	ASSERT_NO_THROW(TNode node(0));
}

TEST(Node, can_create_node_with_first_level)
{
	ASSERT_NO_THROW(TNode node(1));
}

TEST(Node, can_create_node_with_second_level)
{
	ASSERT_NO_THROW(TNode node(2));
}

TEST(Node, can_create_node_with_third_level)
{
	ASSERT_NO_THROW(TNode node(3));
}

TEST(Node, throw_when_create_node_with_wrong_level)
{
	ASSERT_ANY_THROW(TNode node(4));
}

TEST(Node, can_create_node_using_letter)
{
	ASSERT_NO_THROW(TNode node('a'));
}

TEST(Node, can_create_node_using_word)
{
	ASSERT_NO_THROW(TNode node("text"));
}

TEST(Node, throw_when_assign_node_with_different_levels)
{
	TNode node1("text");
	TNode node2;
	ASSERT_ANY_THROW(node2 = node1);
}

TEST(Node, can_assign_node_without_throws)
{
	TNode node1("text");
	TNode node2("newtext");
	ASSERT_NO_THROW(node2 = node1);
}

TEST(Node, can_assign_node_correct)
{
	TNode node1("text");
	TNode node2("newtext");
	node2 = node1;
	EXPECT_EQ(node2.GetNextLevel()->GetLetter(), 't');
	EXPECT_EQ(node2.GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
	TNode::ClearMemory();
}

TEST(Node, can_add_node_without_throws)
{
	TNode word1("text");
	TNode word2("newtext");
	TNode text(0);
	TNode string(1);
	string.SetNextLevel(&word1);
	text.SetNextLevel(&string);
	ASSERT_NO_THROW(text += word2);
}

TEST(Node, can_add_letter_to_node_without_throws)
{
	TNode word("text");
	char letter = 'a';
	TNode text(0);
	TNode string(1);
	string.SetNextLevel(&word);
	text.SetNextLevel(&string);
	ASSERT_NO_THROW(text += letter);
}

TEST(Node, can_add_word_to_tree_without_throws)
{
	TNode word1("text");
	char* word2 = "new";
	TNode text(0);
	TNode string(1);
	text.SetNextLevel(&string);
	string.SetNextLevel(&word1);
	ASSERT_NO_THROW(text += word2);
}

TEST(Node, can_add_node_correct)
{
	TNode word1("text");
	TNode word2("ye");
	TNode text(0);
	TNode string(1);
	text.SetNextLevel(&string);
	string.SetNextLevel(&word1);
	text += word2;
	EXPECT_EQ(text.GetNextLevel()->GetNextLevel()->GetSameLevel()->GetNextLevel()->GetLetter(), 'y');
	EXPECT_EQ(text.GetNextLevel()->GetNextLevel()->GetSameLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
	TNode::ClearMemory();
}

TEST(Node, can_add_letter_to_node_correct)
{
	TNode word("text");
	char letter = 'a';
	TNode text(0);
	TNode string(1);
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	text += letter;
	EXPECT_EQ(word.GetNextLevel()->GetSameLevel()->GetSameLevel()->GetSameLevel()->GetSameLevel()->GetLetter(), 'a');
	TNode::ClearMemory();
}

TEST(Node, can_add_word_to_node_correct)
{
	TNode word1("text");
	char* word2 = "ye";
	TNode text(0);
	TNode string(1);
	text.SetNextLevel(&string);
	string.SetNextLevel(&word1);
	text += word2;
	EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetLetter(), 'y');
	EXPECT_EQ(word1.GetSameLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
	TNode::ClearMemory();
}

TEST(Node, can_convert_node_to_string)
{
	TNode word("text");
	TNode text(0);
	TNode string(1);
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	EXPECT_EQ(text.ToString()[0], 't');
	EXPECT_EQ(text.ToString()[1], 'e');
	EXPECT_EQ(text.ToString()[2], 'x');
	EXPECT_EQ(text.ToString()[3], 't');
	TNode::ClearMemory();
}

TEST(Node, can_create_copy_of_node)
{
	TNode word("text");
	TNode text(0);
	TNode string(1);	
	text.SetNextLevel(&string);
	string.SetNextLevel(&word);
	TNode copy = *text.Clone();
	EXPECT_EQ(copy.GetNextLevel()->GetNextLevel()->GetNextLevel()->GetLetter(), 't');
	EXPECT_EQ(copy.GetNextLevel()->GetNextLevel()->GetNextLevel()->GetSameLevel()->GetLetter(), 'e');
	TNode::ClearMemory();
}

TEST(Node, can_set_next_level_without_throws)
{
	TNode word("text");
	TNode string(1);
	ASSERT_NO_THROW(string.SetNextLevel(&word)); 
	TNode::ClearMemory();
}

TEST(Node, can_correct_set_and_get_next_level)
{
	TNode word("text");
	TNode string(1);
	string.SetNextLevel(&word);
	EXPECT_TRUE(string.GetNextLevel() == &word);
	TNode::ClearMemory();
}

TEST(Node, can_set_same_level_without_throws)
{
	TNode word1("text");
	TNode word2("new");
	ASSERT_NO_THROW(word1.SetSameLevel(&word2));
}

TEST(Node, can_set_and_get_same_level)
{
	TNode word1("text");
	TNode word2("new");
	word1.SetSameLevel(&word2);
	EXPECT_TRUE(word1.GetSameLevel() == &word2);
	TNode::ClearMemory();
}

TEST(Node, can_create_and_delete_node_element)
{
	TNode* word1 = new TNode(0);
	delete word1; //отработал перегруженый оператор удаления
	TNode* word2 = new TNode(1); //память выделили из очереди свободных
	EXPECT_TRUE(word1 == word2); //в итоге у них значения совпадут
	TNode::ClearMemory();
}

//TEST(Node, throw_when_memory_is_end)
//{
//	try
//	{
//		while (1)
//			TNode node("test_memory_is_end"); //пока память есть - создаем
//	}
//	catch (...)
//	{
//		ASSERT_ANY_THROW(TNode node("test_memory_is_end")); //ловим исключение
//	}
//}

TEST(Node, can_set_letter_without_throws)
{
	TNode node('a');
	ASSERT_NO_THROW(node.SetLetter('b'));
}

TEST(Node, can_correct_set_and_get_letter)
{
	TNode node('a');
	node.SetLetter('b');
	EXPECT_EQ(node.GetLetter(), 'b');
	TNode::ClearMemory();
}

TEST(Node, can_set_level_without_throws)
{
	TNode node(0);
	ASSERT_NO_THROW(node.SetLevel(1));
}

TEST(Node, can_correct_set_and_get_level)
{
	TNode node(0);
	node.SetLevel(1);
	EXPECT_EQ(node.GetLevel(), 1);
	TNode::ClearMemory();
}