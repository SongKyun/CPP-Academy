#pragma once

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Pair.h"


class Hashtable
{

	//타입 재정의
	using Entry = TPair<std::string, std::string>;
	// = typedef TPair<std::string, std::string> Entry; 기능상 차이도 없다.

public:
	Hashtable();
	~Hashtable();

	// 함수.
	bool IsEmpty() const;
	void Add(const std::string& key, const std::string& value);
	void Delete(const std::string& key);
	Entry Find(const std::string& key);
	void Print();





private:
	//int GetHash(int key);

	// constexpr 오른쪽 기본형int에만 사용 가능 static을 해줘야 제대로 작동
	static const int bucketCount = 19;
	//TLinkedList<TPair<std::string, std::string>> table[bucketCount];
	TLinkedList<Entry> table[bucketCount];






};

