#include <vector>
#include <iostream>

int main()
{
	//삽입 테스트
	std::vector<int> vector1;
	vector1.reserve(10);

	vector1.emplace_back(20);
	vector1.emplace_back(30);

	std::cout << "삽입 테스트 1\n";

	auto iter = vector1.begin();
	vector1.insert(iter, 10);

	//출력
	for (const auto& item : vector1)
	{
		std::cout << " vector: " << item << std::endl;
	}

	std::cout << "삽입 테스트2 \n";

	//두번째 위치에 200을 2개 삽입
	iter = vector1.begin();
	vector1.insert(++iter, 2, 200);

	//출력
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cout << "삽입 테스트3\n";
	//initialize_list로 초기화
	std::vector<int> vector2({ 1000, 2000, 3000 });
	iter = vector1.begin();
	iter += 2; // 세번째 위치
	//다른 벡터에 있는 데이터 삽입
	vector1.insert(iter, vector2.begin(), vector2.end());

	//출력
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cout << "삽입 테스트4\n";
	iter = vector1.begin();
	iter += 3;
	vector1.insert(iter, { 500, 600 ,700 });

	//출력
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cin.get();

	// 
}