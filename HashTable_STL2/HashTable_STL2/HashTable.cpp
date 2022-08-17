#include "HashTable.h"

//키 생성 함수
int GenerateKey(const string& keyString)
{
	int key = 0;
	for (size_t ix = 0; ix < keyString.length(); ++ix)
	{
		//가중치 적용 방법.
		//key += keyString[ix] * (ix + 1);

		// JDK에서 사용하는 방법
		key = key * 31 + keyString[ix];
	}
	return abs(key);
}

HashTable::HashTable()
{

}

HashTable::~HashTable()
{

}

bool HashTable::IsEmpty() const
{
	size_t sum = 0;
	for (size_t ix = 0; ix < hashCount; ++ix)
	{
		sum += table[ix].size();
	}
	return sum == 0;
}

void HashTable::Add(const string& key, const string& value)
{
	//해시 구하기
	//버킷 번호 = 인덱스
	int bucketIndex = GenerateKey(key) % hashCount;

	//값 추가/변경할 위치
	list<Entry>& position = table[bucketIndex];

	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		//동일한 데이터가 있는지 검색.
		if (iter->first == key && iter->second == value)
		{
			//hashKey = true;
			cout << "이미 동일한 데이터가 저장돼 있습니다\n";
			return;
		}
	}

	//동일한 데이터가 없으면 값 추가
	position.emplace_back(Entry(key, value));

}

void HashTable::Delete(const string& key)
{
	//해시 값 구하기
	int buckeIndex = GenerateKey(key) % hashCount;

	//위치 가져오기
	auto& position = table[buckeIndex];

	//검색
	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		//전달한 데이터를 찾으면 삭제.
		if (iter->first == key)
		{
			position.erase(iter);
			cout << "항목이 삭제되었습니다.\n";

			return;
		}
	}
	//못찾은 경우
	cout << " 데이터를 찾지 못했습니다. \n";
}

HashTable::Entry HashTable::Find(const string& key)
{
	//검색
	int buckeIndex = GenerateKey(key) % hashCount;
	if (table[buckeIndex].size() == 0 )
	{
	cout << "해당 키로 데이터를 찾지 못했습니다 \n";
	return Entry("", "");
	}

	//순회
	for (auto iter = table[buckeIndex].begin(); iter != table[buckeIndex].end(); ++iter)
	{
		if (iter->first == key)
		{
			return *iter;
		}
	}
	cout << "해당 키로 데이터를 찾지 못했습니다 \n";
	return Entry("","");
}

void HashTable::Print()
{
	for (int ix = 0; ix < hashCount; ++ix)
	{
		if (table[ix].size() == 0)
		{
			continue;
		}

		for (auto iterator = table[ix].begin(); iterator != table[ix].end(); ++iterator)
		{
			cout << "Key: " << iterator->first
				<< " Value: " << iterator->second << endl;
		}
	}
}

