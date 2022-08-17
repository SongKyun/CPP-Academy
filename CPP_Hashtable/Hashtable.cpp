#include "Hashtable.h"
//해시 함수
int GenerateKey(const std::string& keyString)
{
	int key = 0;
	for (size_t ix = 0; ix < keyString.length(); ++ix)
	{
		// 가중치 적용 방식
		//key += keyString[ix] * (ix + 1);

		//JDK에서 사용하는 구현방식
		key = key * 31 + keyString[ix];
	}
	//절대값 구하기
	return std::abs(key);
}


// h/cpp 전환 단축키 ctrl + k > ctrl + o
Hashtable::Hashtable()
{
}

Hashtable::~Hashtable()
{
}
//해시 테이블이 비었는지 확인
bool Hashtable::IsEmpty() const
{
	size_t sum = 0;
	// table -> 링크드리스트의 배열.
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		sum += table[ix].Count();

		//sum = sum + table[ix].Count();
	}

	return sum == 0;
}

//데이터 추가.
void Hashtable::Add(const std::string& key, const std::string& value)
{
	// 해시 생성 후, 버킷 인덱스 구하기.
	int bucketIndex = GenerateKey(key) % bucketCount;

	//앞 서 구한 인덱스에 위치한 링크드 리스트에 접근
	auto& position = table[bucketIndex];

	//이미 동일한 키의 데이터가 저장돼 있는지 확인 (중복확인)
	for (size_t ix = 0; ix < position.Count(); ++ix)
	{
		//f12 / Ctrl + -
		if (position[ix]->data.key == key)
		{
			std::cout << "이미 동일한 키의 데이터가 저장돼 있습니다\n";
			return;
		}
	}

	//중복된 데이터가 없으면 데이터 추가
	position.PushLast(Entry(key, value));
}

void Hashtable::Delete(const std::string& key)
{
	//해시 생성 후, 버킷 인덱스 구하기
	int bucketIndex = GenerateKey(key) % bucketCount;
	//해당 인덱스의 링크드리스트에 접근
	auto& position = table[bucketIndex];

	//링크드리스트에 저장된 데이터에서 전달받은 키의 데이터가 있는지 확인
	//찾은 경우 -> 삭제

	for (size_t ix = 0; ix < position.Count(); ++ix)
	{
		position.Delete(position[ix]->data);
		std::cout << "항목이 삭제되었습니다.\n";

		return;
	}
}

Hashtable::Entry Hashtable::Find(const std::string& key)
{
	//해시 생성 후 , 버킷 인덱스 구하기
	int bucketIndex = GenerateKey(key) % bucketCount;

	if (table[bucketIndex].Count() == 0)
	{
		std::cout << "해당 키의 데이터를 찾지 못했습니다 \n";
		return Entry("", "");
	}

	for (size_t ix = 0; ix < table[bucketIndex].Count(); ++ix)
	{
		if (table[bucketIndex][ix]->data.key == key)
		{
			//검색 성공하면 해당 데이터 반환
			return table[bucketIndex][ix]->data;
		}
	}
	std::cout << "해당 키의 데이터를 찾지 못했습니다\n";
	return Entry();
}

void Hashtable::Print()
{
	//배열 순회
	for (size_t ix = 0; ix < bucketCount; ++ix)
	{
		// 링크드 리스트가 비었으면 건너뛰기
		if (table[ix].Count() == 0)
		{
			continue;
		}

		// 데이터 출력
		for (size_t jx = 0; jx < table[ix].Count(); ++jx)
		{
			std::cout << "키: " << table[ix][jx]->data.key
				<< "값: " << table[ix][jx]->data.value << std::endl;
		}
	}
}
