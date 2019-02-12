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
  TQueue<char> queue(str.GetLength() * 3); //выделение памяти "с запасом, т.к. вводим дополнительные символы, для разграничения чисел"
  TStack<char> stack(str.GetLength() * 3);
  for (int i = 0; i < str.GetLength(); i++)
  {
    if (i == 0)
    {
      if (str[0] == '-') //обработка унарного минуса
      {
        queue.Put('[');
        queue.Put('0');
        queue.Put(']');
      }
      else 
        if (IsOperation(str[0]))
          if ((GetPriority(str[0]) != 1)) //первой операцией может быть только скобка
            throw TException("Invalid expression entry.");
    }
    if (isdigit(str[i]))
    {
      queue.Put('['); //ограничитель для числа
      while ((i < str.GetLength()) && isdigit(str[i + 1]))
      {
        queue.Put(str[i]); //запихиваем цифры числа в очередь
        i++;
      }
      queue.Put(str[i]); //последняя цифра числа
      queue.Put(']'); //ограничитель для числа
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
                queue.Put(stack.Get()); //операции из стека переносим в очередь
              stack.Get(); //вытаскиваем открывающую скобку из стека
            }
            else //если текущая операция не '(' или ')', то
            {
              int p = GetPriority(str[i]);
              if (p > GetPriority(stack.TopView()))
                stack.Put(str[i]);
              else 
                if (p <= GetPriority(stack.TopView()))
                {
                  while (!stack.IsEmpty() && p <= GetPriority(stack.TopView()))
                    queue.Put(stack.Get()); //если приоритет очередной операции не больше, чем у последней в стеке операций, то переносим их в очередь
                  stack.Put(str[i]); //очередную операцию в стек операций
                }
            }
        }
        else //если не число и не операция, то проверка на конец строки, иначе "мусор"
          if (str[i] != '\0')
            throw TException("The line incorrect."); 
  } //конец цикла for, обработана вся входная строка
  while (!stack.IsEmpty())
    queue.Put(stack.Get()); //операции, оставшиеся в стеке, переносим в очередь
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
        tmp = tmp * 10 + std::atof(&element); //собираем число
      }
      queue.Get(); //вытаскиваем закрывающую скобку
      stack.Put(tmp); //полученное число в стек
    }
    else 
      if (IsOperation(element))
      {
        double rightOperand = stack.Get(); //достаем сначала правый операнд, т.к. в стек он попал позже левого
        double leftOperand = stack.Get(); //затем левый
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
