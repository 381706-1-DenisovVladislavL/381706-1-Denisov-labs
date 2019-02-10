#include <gtest.h>

#include "Polish.h"

TEST(Polish, can_get_priority)
{

  ASSERT_EQ(1, GetPriority(')'));
  ASSERT_EQ(1, GetPriority('('));
  ASSERT_EQ(2, GetPriority('+'));
  ASSERT_EQ(2, GetPriority('-'));
  ASSERT_EQ(3, GetPriority('*'));
  ASSERT_EQ(3, GetPriority('/'));
  ASSERT_ANY_THROW(GetPriority('!'));
}

TEST(Polish, can_check_is_op)
{
  ASSERT_TRUE(IsOperation(')'));
  ASSERT_TRUE(IsOperation('('));
  ASSERT_TRUE(IsOperation('+'));
  ASSERT_TRUE(IsOperation('-'));
  ASSERT_TRUE(IsOperation('*'));
  ASSERT_TRUE(IsOperation('/'));
  ASSERT_FALSE(IsOperation('4'));
  ASSERT_FALSE(IsOperation('!'));
}

TEST(Polish, can_convert_to_polish)
{
  char arr[] = "2+3";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  ASSERT_EQ(rpn.Get(), '[');
  ASSERT_EQ(rpn.Get(), '2');
  ASSERT_EQ(rpn.Get(), ']');
  ASSERT_EQ(rpn.Get(), '[');
  ASSERT_EQ(rpn.Get(), '3');
  ASSERT_EQ(rpn.Get(), ']');
  ASSERT_EQ(rpn.Get(), '+');
}

TEST(Polish, can_calculate_expression_of_one_positive_member)
{
  char arr[] = "5";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(5, Calculate(rpn));
}

TEST(Polish, can_calculate_expression_of_one_negative_member)
{
  char arr[] = "-5";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(-5, Calculate(rpn));
}


TEST(Polish, can_add)
{
  char arr[] = "1+2";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(3, Calculate(rpn));
}

TEST(Polish, can_subtraction)
{
  char arr[] = "3-2";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(1, Calculate(rpn));
}

TEST(Polish, can_multiplication)
{
  char arr[] = "3*4";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(12, Calculate(rpn));
}

TEST(Polish, can_division)
{
  char arr[] = "4/2";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(2, Calculate(rpn));
}

TEST(Polish, can_perform_an_action_with_negative_first_number)
{
  char arr[] = "-5+20";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(15, Calculate(rpn));
}


TEST(Polish, can_perform_an_action_with_two_digit_numbers) 
{
  char arr[] = "12+38";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(50, Calculate(rpn));
}

TEST(Polish, can_perform_an_action_with_more_than_two_members)
{
  char arr[] = "2*3*4";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(24, Calculate(rpn));
}

TEST(Polish, can_follow_the_order_of_operations_without_brackets)
{
  char arr[] = "2+3*4";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(14, Calculate(rpn));
}

TEST(Polish, can_follow_the_order_of_operations_with_brackets)
{
  char arr[] = "(2+3)*4";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(20, Calculate(rpn));
}

TEST(Polish, can_follow_the_order_of_operations_with_nested_brackets)
{
  char arr[] = "(4/(1+1)-4)*4";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(-8, Calculate(rpn));
}

TEST(Polish, can_follow_the_order_of_operations_with_several_brackets)
{
  char arr[] = "(33+11)/(2+2)";
  TString str(arr);
  TQueue<char> rpn;
  rpn = ConvertToPol(str);
  EXPECT_EQ(11, Calculate(rpn));
}

TEST(Polish, throw_when_expression_contains_an_invalid_character)
{
  char arr[] = "1!2";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, no_throw_when_all_expression_in_brackets_and_correctly_result)
{
  char arr[] = "(2*3)";
  TString str(arr);
  TQueue<char> rpn;
  ASSERT_NO_THROW(ConvertToPol(str));
  rpn = ConvertToPol(str);
  ASSERT_EQ(6, Calculate(rpn));
}

TEST(Polish, throw_when_expression_contains_an_incorrect_number_of_brackets_1)
{
  char arr[] = "(2*3";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_expression_contains_an_incorrect_number_of_brackets_2)
{
  char arr[] = "((2*3)";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_expression_contains_an_incorrect_number_of_brackets_3)
{
  char arr[] = "(2*3))";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_expression_contains_an_incorrect_number_of_brackets_4)
{
  char arr[] = "2*3)";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_expression_is_constructed_incorrectly)
{
  char arr[] = "*3*2";
  TString str(arr);
  ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_rpn_is_incorrectly_1)
{
  TQueue<char> rpn(7);
  rpn.Put('+');
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('[');
  rpn.Put('2');
  rpn.Put(']');
  ASSERT_ANY_THROW(Calculate(rpn));
}

TEST(Polish, throw_when_rpn_is_incorrectly_2)
{
  TQueue<char> rpn(7);
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('+');
  rpn.Put('[');
  rpn.Put('2');
  rpn.Put(']');
  ASSERT_ANY_THROW(Calculate(rpn));
}

TEST(Polish, throw_when_rpn_is_incorrectly_3)
{
  TQueue<char> rpn(10);
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('+');
  rpn.Put('[');
  rpn.Put('2');
  rpn.Put(']');
  ASSERT_ANY_THROW(Calculate(rpn));
}

TEST(Polish, throw_when_rpn_is_incorrectly_4)
{
  TQueue<char> rpn(7);
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('[');
  rpn.Put('2');
  rpn.Put(']');  
  rpn.Put('!');
  ASSERT_ANY_THROW(Calculate(rpn));
}

TEST(Polish, throw_when_rpn_is_incorrectly_5)
{
  TQueue<char> rpn(8);
  rpn.Put('[');
  rpn.Put('1');
  rpn.Put(']');
  rpn.Put('[');
  rpn.Put('2');
  rpn.Put(']');
  rpn.Put('+');
  rpn.Put('+');
  ASSERT_ANY_THROW(Calculate(rpn));
}