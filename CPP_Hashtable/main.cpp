#include <iostream>
#include "Hashtable.h"

int main()
{
	//해쉬 테이블 생성
	Hashtable table;

	//데이터 추가
	table.Add("Ronnie", " 010-123456789");
	table.Add("Kevin", " 010-123474789");
	table.Add("Baker", " 010-123457789");
	table.Add("Taejun", " 010-125556789");
	table.Add("Ronnie", " 010-123456689");

	//출력
	table.Print();
	
	//검색
	auto find = table.Find("Ronnie");
	if (find.value.size() > 0)
	{
		std::cout << "검색 결과: " << find.key << " , " << find.value << std::endl;
	}

	//삭제
	table.Delete("Ronnie");
	table.Delete("Kevin");

	// 출력
	table.Print();

	std::cin.get();

}