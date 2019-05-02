#pragma once
#include "../TextLib/NodeIter.h"

class TText : public TNode
{
protected:
	TNode* root; //������ ������
public:
	TText(const char* string); //����������� �������������� ������ � �����
	TText(TText& text); //����������� �����������
	TText(TNode& node); //����������� �������������� ����

	TNode* GetRoot(); //��������� ��������� �� ������ ������

	void Insert(const int pos, const char* string); //������� ������ � ��������� �������
	void Insert(TNode* start, TNode* string); //������� ������ �� ���������� �������� � ������

	int Find(const char* string); //����� ������� ������ � ������
	TNode* FindNode(const char* string); //����� �������� � ������ �� ��������� ������

	char* Copy(const int start, const int len); //����������� ����� ��������� ������� start �������� � ���-�� len
	TNode* Copy(TNode* start, const int len); //����������� ����� ���������� �������� ������ -//-

	void Delete(const int start_del, const int lenght); //�������� � ��������� ������� -//-
	void Delete(TNode* start_del, const int lenght); //�������� � ���������� �������� ������ -//-
};