#pragma once

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Pair.h"


class Hashtable
{

	//Ÿ�� ������
	using Entry = TPair<std::string, std::string>;
	// = typedef TPair<std::string, std::string> Entry; ��ɻ� ���̵� ����.

public:
	Hashtable();
	~Hashtable();

	// �Լ�.
	bool IsEmpty() const;
	void Add(const std::string& key, const std::string& value);
	void Delete(const std::string& key);
	Entry Find(const std::string& key);
	void Print();





private:
	//int GetHash(int key);

	// constexpr ������ �⺻��int���� ��� ���� static�� ����� ����� �۵�
	static const int bucketCount = 19;
	//TLinkedList<TPair<std::string, std::string>> table[bucketCount];
	TLinkedList<Entry> table[bucketCount];






};

