#pragma once

#include "LinkedList.h"
#include <string>

class Program
{
public:
	//������.
	Program();

	//�Ҹ���
	~Program();

	//������ �Լ�.
	void InsertLoop();
	void DeleteLoop();

private:
	//���ڿ� ���� ������ ��ũ�帮��Ʈ.
	LinkedList<std::string>* list;
};

