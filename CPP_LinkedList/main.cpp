#include <iostream>
#include "LinkedList.h"
#include <string>

int main()
{
	// 리스트 생성
	LinkedList* list = new LinkedList();
	
	// 콘솔에서 입력 받기 위해 선언
	std::string input; 

	//무한 루프
	// 1. 탈출(종료)조건부터 생각하기
	while (true)
	{
		std::cout << "추가할 데이터를 입력해주세요(종료는 q)\n";

		std::cin >> input;

		if (input == "q" || input == "Q")
		{
			break;
		}

		//데이터 추가. std::stoi() -> 문자열을 숫자로 변환
		list->Insert(std::stoi(input));

		list->Print();
		
	}

	// 무한루프.
	// 데이터 삭제를 입력 받아 처리

	input = ""; // 변수 초기화
	while (true)
	{
		std::cout << "삭제할 데이터를 입력해주세요(종료는q)\n";

		std::cin >> input;

		if (input == "q" || input == "Q")
		{
			break;
		}

		list->DeleteDate(std::stoi(input));

		list->Print();
	}
	
	// 출력.
	list->Print();

	delete list;

	std::cin.get();
}