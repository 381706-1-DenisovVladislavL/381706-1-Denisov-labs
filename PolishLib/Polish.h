#pragma once
#include "Queue.h"
#include "MyString.h"

int GetPriority(const char operation);
bool IsOperation(char symbol);
TQueue<char> ConvertToPol(TString str);
double Calculate(TQueue<char> queue);
