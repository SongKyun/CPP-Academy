#include <list>
#include <iostream>

int main()
{
	//삽입

	//생성
	std::list<int> list1;

	list1.push_back(20);
	list1.push_back(30);

	std::cout << "삽입 테스트1 : " << std::endl;

	//첫 번쨰 위치에 삽입
	std::list<int>::iterator iter = list1.begin();
	list1.insert(iter, 100);

	//출력
	for (auto& item : list1)
	{
		std::cout << "list1: " << item << std::endl;
	}

	std::cout << "삽입 테스트 2" << std::endl;

	// 두 번째 위치에 200을 2개 삽입
	iter = list1.begin();
	++iter;
	list1.insert(iter, 2, 200);
	//출력
	for (auto& item : list1)
	{
		std::cout << "list 1: " << item << std::endl;
	}

	//

	std::cout << "삽입 테스트 3 " << std::endl;

	std::list<int> list2;
	list2.emplace_back(1000); // push 는 함수가 2개인데 참조해서 메모리에 복사가 일어나는데 emplace는 함수가 1개뿐이라 메모리 면에서 더 좋다
	list2.push_back(2000);
	list2.push_back(3000);

	//두 번째 위치에 list2의 모든 데이터 삽입
	iter = list1.begin();
	++iter;
	list1.insert(iter, list2.begin(), list2.end());

	//출력
	for (auto& item : list1)
	{
		std::cout << "list 1: " << item << std::endl;
	}

	std::cin.get();
}