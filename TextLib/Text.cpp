#include "../TextLib/Text.h"

TText::TText(const char* string)
{
	root = new TNode(0); //0 уровень - уровень текста, создаем корень текста
	root->SetNextLevel(new TNode(1)); //создаем первую строку в тексте
	TNode* tmp = root->GetNextLevel();
	char* word;
	int len = strlen(string);
	int space_pos[100]; //позиции пробелов в тексте
	int space_count = 0; //число пробелов
	int iter = 0; //итератор по отдельно взятому слову
	for (int i = 0; i < len; i++)
		if (string[i] == ' ')
		{
			if (space_count > 98) //строка не содержит ни одного символа, кроме пробелов
				throw TException("Error.");
			space_pos[space_count] = i; 
			space_count++;
		}
	space_pos[space_count] = len; 
	word = new char[space_pos[0] + 1]; //позиция первого пробела = длина первого слова
	space_count = 0;
	for (int i = 0; i <= len; i++)
	{
		if (string[i] != ' ' && i != len) //заполняем слово
		{
			word[iter] = string[i];
			iter++;
		}
		else if (string[i] == ' ' || i == len) //если слово или строка закончились
		{
			word[iter] = 0; //разделитель
			if (i == iter) //выполнится только для 1го слова
			{
				tmp->SetNextLevel(new TNode(word));  //создаем первое слово в строке
				tmp = tmp->GetNextLevel();  //переходим к этому слову
			}
			else
			{
				tmp->SetSameLevel(new TNode(word)); //создаем очередное слово в строке (со 2го и дальше)
				tmp = tmp->GetSameLevel(); //переходим к этому слову
			}
			delete[] word;
			iter = 0; //подготовка к обработке следующего слова
			if (i == len) //строка закончилась - завершаем обработку в целом
				break;
			word = new char[space_pos[space_count + 1] - space_pos[space_count]]; //память под следующее слово
		}
	}
}

TText::TText(TText& text)
{
	root = text.Clone(); //т.к TText унаследован от TNode, для которого существует Clone()
}

TText::TText(TNode& node)
{
	root = new TNode(0);
	root->SetNextLevel(new TNode(1));
	root->GetNextLevel()->SetNextLevel(new TNode(*(node.GetNextLevel()->GetNextLevel())));
}

TNode* TText::GetRoot()
{
	return root;
}

void TText::Insert(const int pos, const char* string)
{
	int string_len = strlen(string);
	TNode* str = new TNode(string[0]); //создаем первую букву вставляемого слова
	TNode* start_str = str; //указатель на начало вставляемого слова, под которое уже выделена память
	int i = 1;
	for (i; i < string_len; i++) //выполняем создание последующих букв вставляемого слова
	{
		str->SetSameLevel(new TNode(string[i])); 
		str = str->GetSameLevel(); //используем str в качестве итератора по вставляемому слову
	}
	TNodeIter iter(root);
	int len = 0;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetLevel() == 2 && pos == 0) //если вставка в начало
		{
			iter.PutInStack(tmp); //делаем так, чтобы при выполнении перехода к следующему мы оказались на бывшем начале текста
			break;
		}
		if (tmp->GetLevel() == 3) //если находимся на уровне буквы, то увеличиваем число пройденных букв на 1
			len++;
		if (len == pos - 1) //если находимся на предыдущей от вставляемой позиции, выходим из цикла
			break;
	}
	TNode* point = iter.GoNext(); //переходим к вставляемой позиции
	if (pos == 0)
	{
		str->SetSameLevel(point->GetNextLevel()); //после последней буквы вставляемой строки будет идти первая буква бывшей первой строки
		point->SetNextLevel(start_str); //изменяем начало
	}
	else
	{
		str->SetSameLevel(point->GetSameLevel()); //после последней буквы вставляемой буквы будет идти буква с места вставки
		point->SetSameLevel(start_str); //с позиции, в которую производилась вставка теперь начинается вставляемое слово
	}
}

//вставка после start
void TText::Insert(TNode* start, TNode* string)
{
	TNode* tmp1 = new TNode(*string);
	TNode* tmp2 = root;
	TNodeIter iter(root);
	while (tmp2 != start)
	{
		tmp2 = iter.GoNext();
	}
	tmp1->SetSameLevel(tmp2->GetSameLevel()); //после вставляемой строки должно стоять то, что стояло после start в исходном тексте
	tmp2->SetSameLevel(tmp1); //после start теперь будет стоять полученная строка string
}

int TText::Find(const char* string)
{
	TNodeIter iter(root);
	int len = strlen(string);
	int i = 0;
	int pos = 0; 
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetLevel() == 3 && tmp->GetLetter() == string[i]) //если наткнулись на первую букву, то сравниваем остальные
			i++;
		else if (tmp->GetLevel() == 3 && tmp->GetLetter() != string[i]) //если на какой-то прервались
		{
			if (i != 0) //если хоть немного успели пройти
			{
				iter.PutInStack(tmp); //предыдущее начало поиска в стек, чтобы потом продолжить со следующего после него
				pos += i; //искомая позиция сдвигается на число уже пройденных букв
				i = 0; //для удобства работы со строкой при сравнении букв
			}
			else
				pos++; //идем до первой подходящей позиции для начала поиска
		}
		if (i == len) //если прошли весь искомый текст
			break;
	}
	return pos;
}

TNode* TText::FindNode(const char* string)
{
	TNodeIter iter(root);
	TNode* res = NULL;
	int len = strlen(string);
	int i = 0;
	int pos = 0;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetLevel() == 3 && tmp->GetLetter() == string[i])
		{
			if (i == 0)
				res = tmp;
			i++;
		}
		else if (tmp->GetLevel() == 3 && tmp->GetLetter() != string[i])
		{
			if (i != 0)
			{
				iter.PutInStack(tmp);
				res = NULL;
				i = 0;
			}
		}
		if (i == len)
			break;
	}
	return res;
}

char* TText::Copy(const int start, const int len)
{
	char* res = new char[len];
	TNodeIter iter(root);
	int i = 0;
	int pos = 0;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetLevel() == 3 && pos == start + i)
		{
			pos++;
			res[i] = tmp->GetLetter();
			i++;
		}
		else if (tmp->GetLevel() == 3)
			pos++;
		if (i == len)
			break;
	}
	return res;
}

TNode* TText::Copy(TNode* start, const int len)
{
	TNode* res = new TNode(0);
	TNode* res_s = new TNode(1);
	TNode* res_w = new TNode(*start);
	res->SetNextLevel(res_s);
	res_s->SetNextLevel(res_w);
	TNodeIter iter(root);
	int i = len;
	bool flag = false;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp == start)
		{
			i--;
			flag = true;
		}
		else if (flag == true && tmp->GetLevel() == 3)
		{
			res_w->SetSameLevel(new TNode(*tmp));
			res_w = res_w->GetSameLevel();
			i--;
		}
		if (i == 0)
			break;
	}
	return res;
}

void TText::Delete(const int start_del, const int lenght)
{
	TNodeIter iter(root);
	int i = 0;
	int pos = 0;
	TNode* temp1 = NULL;
	TNode* temp2;
	bool flag = false;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetLevel() == 3 && flag == false)
		{
			pos++;
			if (pos == start_del)
			{
				tmp->SetSameLevel(NULL);
				temp1 = tmp;
			}
		}
		if (tmp->GetLevel() == 3 && pos - 1 == start_del)
		{
			temp2 = tmp->GetSameLevel();
			delete tmp;
			pos++;
			i++;
			flag = true;
		}
		else if (tmp->GetLevel() == 3 && pos - 1 == start_del + i)
		{
			TNode* tmp_1 = tmp;
			if (i == lenght - 1)
				temp2 = tmp->GetSameLevel();
			delete tmp_1;
			pos++;
			i++;
		}
		if (i == lenght)
			break;
	}
	temp1->SetSameLevel(temp2);
	//root->GarbageCollector();
}

void TText::Delete(TNode* start_del, const int lenght)
{
	TNodeIter iter(root);
	int i = lenght;
	bool flag = false;
	bool nextflag = false;
	bool sameflag = false;
	TNode* temp1;
	TNode* temp2;
	TNode* temp3;
	while (iter.IsEnd() != true)
	{
		TNode* tmp = iter.GoNext();
		if (tmp->GetSameLevel() == start_del)
		{
			temp1 = tmp;
			sameflag = true;
		}
		if (tmp->GetNextLevel() == start_del)
		{
			temp3 = tmp;
			nextflag = true;
		}
		if (tmp == start_del)
		{
			delete tmp;
			i--;
			flag = true;
		}
		else if (flag == true && tmp->GetLevel() == 3)
		{
			if (i == 1)
				temp2 = tmp->GetSameLevel();
			delete tmp;
			i--;
		}
		if (i == 0)
			break;
	}
	if (nextflag == true)
		temp3->SetNextLevel(temp2);
	if (sameflag == true)
		temp1->SetNextLevel(temp2);
	//root->GarbageCollector();
}