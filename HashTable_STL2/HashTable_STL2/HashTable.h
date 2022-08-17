#pragma once

#include <list>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class HashTable
{
	using Entry=pair<string, string>;

public:
	HashTable();
	~HashTable();

	bool IsEmpty() const;
	void Add(const string& key, const string& value);
	void Delete(const string& key);
	Entry Find(const string& key);
	void Print();

private:

	static const int hashCount = 19;
	list<Entry> table[hashCount];
};