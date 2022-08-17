#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
	// 해시 테이블 생성.
	HashTable table;

	// 데이터 추가.
	table.Add("Ronnie", "010-12345678");
	table.Add("Kevin", "010-32979287");
	table.Add("Baker", "010-29871982");
	table.Add("Taejun", "010-39487298");

	// 출력.
	table.Print();

	// 검색.
	auto find = table.Find("Ronnie");
	if (find.first.size() > 0)
	{
		cout << "검색 결과: " << find.first << " , " << find.second << endl;
	}

	// 삭제.
	table.Delete("Ronnie");

	table.Print();

	cin.get();
}