#include <cstdlib>
#include "Polish.h"

int GetPriority(const char operation)
{
  switch (operation)
  {
  case '(':
    return 1;
  case ')':
    return 1;
  case '+':
    return 2;
  case '-':
    return 2;
  case '*':
    return 3;
  case '/':
    return 3;
  default:
    throw TException("Invalid character.");
  }
}

bool IsOperation(char symbol)
{
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '(' || symbol == ')');
}

TQueue<char> ConvertToPol(TString str)
{
  int openCounter = 0, closeCounter = 0;
  TQueue<char> queue(str.GetLength() * 3); //��������� ������ "� �������, �.�. ������ �������������� �������, ��� ������������� �����"
  TStack<char> stack(str.GetLength() * 3);
  for (int i = 0; i < str.GetLength(); i++)
  {
    if (i == 0)
    {
      if (str[0] == '-') //��������� �������� ������
      {
        queue.Put('[');
        queue.Put('0');
        queue.Put(']');
      }
      else 
        if (IsOperation(str[0]))
          if ((GetPriority(str[0]) != 1)) //������ ��������� ����� ���� ������ ������
            throw TException("Invalid expression entry.");
    }
    if (isdigit(str[i]))
    {
      queue.Put('['); //������������ ��� �����
      while ((i < str.GetLength()) && isdigit(str[i + 1]))
      {
        queue.Put(str[i]); //���������� ����� ����� � �������
        i++;
      }
      queue.Put(str[i]); //��������� ����� �����
      queue.Put(']'); //������������ ��� �����
    }
    else 
      if (stack.IsEmpty() && IsOperation(str[i]))
      {
        stack.Put(str[i]);
        if (str[i] == '(')
          openCounter++;
        if (str[i] == ')')
          throw TException("Invalid expression entry.");
      }
      else
        if (IsOperation(str[i]))
        {
          if (str[i] == '(')
          {
            stack.Put(str[i]);
            openCounter++;
          }
          else
            if (str[i] == ')')
            {
              closeCounter++;
              while (stack.TopView() != '(') 
                queue.Put(stack.Get()); //�������� �� ����� ��������� � �������
              stack.Get(); //����������� ����������� ������ �� �����
            }
            else //���� ������� �������� �� '(' ��� ')', ��
            {
              int p = GetPriority(str[i]);
              if (p > GetPriority(stack.TopView()))
                stack.Put(str[i]);
              else 
                if (p <= GetPriority(stack.TopView()))
                {
                  while (!stack.IsEmpty() && p <= GetPriority(stack.TopView()))
                    queue.Put(stack.Get()); //���� ��������� ��������� �������� �� ������, ��� � ��������� � ����� ��������, �� ��������� �� � �������
                  stack.Put(str[i]); //��������� �������� � ���� ��������
                }
            }
        }
        else //���� �� ����� � �� ��������, �� �������� �� ����� ������, ����� "�����"
          if (str[i] != '\0')
            throw TException("The line incorrect."); 
  } //����� ����� for, ���������� ��� ������� ������
  while (!stack.IsEmpty())
    queue.Put(stack.Get()); //��������, ���������� � �����, ��������� � �������
  if (openCounter != closeCounter)
    throw TException("The number of open and closed brackets does not match.");
  return queue;
}

double Calculate(TQueue<char> queue)
{
  double result = 0;
  TStack<double> stack(queue.GetSize());
  if (IsOperation(queue.TopView()))
    throw TException("The Polish entry is not correct.");
  while (!queue.IsEmpty())
  {
    char element = queue.Get();
    if (element == '[')
    {
      element = queue.Get();
      double tmp = std::atof(&element);
      while (queue.TopView() != ']' && !queue.IsEmpty())
      {
        element = queue.Get();
        tmp = tmp * 10 + std::atof(&element); //�������� �����
      }
      queue.Get(); //����������� ����������� ������
      stack.Put(tmp); //���������� ����� � ����
    }
    else 
      if (IsOperation(element))
      {
        double rightOperand = stack.Get(); //������� ������� ������ �������, �.�. � ���� �� ����� ����� ������
        double leftOperand = stack.Get(); //����� �����
        double res = 0;
        if (element == '+')
          res = leftOperand + rightOperand;
        if (element == '-')
          res = leftOperand - rightOperand;
        if (element == '*')
          res = leftOperand * rightOperand;
        if (element == '/')
          res = leftOperand / rightOperand;
        stack.Put(res);
      }
      else 
        throw TException("The Polish entry is not correct.");
  }
  result = stack.Get();
  if (!stack.IsEmpty())
    throw TException("The Polish entry is not correct.");
  return result;
}
