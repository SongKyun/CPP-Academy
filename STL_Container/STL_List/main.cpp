// C++ OOP 객체 지향 프로그래밍
// Object-Oriented-Programming
// Class - Data + Function

#include <list>
#include <iostream>

// 아이템 구조체.
struct Item
{
	Item(int itemCode = 0, int price = 0)
		: itemCode(itemCode), price(price)
	{
	}

	int itemCode;
	int price;
};

// 데이터 출력용 연산자 오버로딩.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "아이템 코드: " << item.itemCode << ", 가격: " << item.price;
}

// 정렬에 사용할 함수 객체 선언.
// 함수 객체.
// 클래스에 함수 오버로딩이 된 객체.
struct ItemLessComparer
{
	bool operator()(const Item& left, const Item& right)
	{
		return left.itemCode < right.itemCode;
	}
};

struct ItemGreaterComparer
{
	bool operator()(const Item& left, const Item& right)
	{
		return left.itemCode > right.itemCode;
	}
};

int main()
{
	// 리스트 생성.
	std::list<Item> itemList;

	// 추가.
	// 앞에 추가.
	Item item1(1, 200);
	itemList.push_front(item1);
	Item item2(2, 1000);
	itemList.push_front(item2);

	// 뒤에 추가.
	Item item3(3, 3000);
	itemList.push_back(item3);
	Item item4(4, 4500);
	itemList.push_back(item4);

	// 출력.
	// end() 반복자 저장.
	std::list<Item>::iterator iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// 순회.
	//for (auto iter = itemList.begin(); iter != iterEnd; ++iter)
	for (std::list<Item>::iterator iter = itemList.begin();
		iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	// 삭제.
	// 앞 데이터 삭제.
	itemList.pop_front();

	// 데이터 읽기.
	auto frontItem = itemList.front();

	// 출력.
	std::cout << frontItem << " , " << itemList.back() << std::endl;

	Item item6(6, 3000);
	itemList.push_back(item6);
	Item item5(5, 4500);
	itemList.push_back(item5);

	Item item8(8, 3000);
	itemList.push_back(item8);
	Item item7(7, 4500);
	itemList.push_back(item7);

	// 정렬.
	ItemLessComparer lessComparer;
	itemList.sort(lessComparer);

	std::cout << "===============================\n";

	// 출력.
	// end() 반복자 저장.
	iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// 순회.
	//for (auto iter = itemList.begin(); iter != iterEnd; ++iter)
	for (std::list<Item>::iterator iter = itemList.begin();
		iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	ItemGreaterComparer greaterComparer;
	//itemList.sort(greaterComparer);
	// lambda.
	itemList.sort(
		[](const Item& left, const Item& right) -> bool
		{
			return left.itemCode > right.itemCode;
		}
	);

	std::cout << "===============================\n";

	// 출력.
	// end() 반복자 저장.
	iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// 순회.
	//for (auto iter = itemList.begin(); iter != iterEnd; ++iter)
	for (std::list<Item>::iterator iter = itemList.begin();
		iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	//리스트 비우기.
	itemList.clear();
	auto count = itemList.size();
	std::cout << " 남아 있는 아이템 개수 : " << count << std::endl;

	std::cin.get();
}