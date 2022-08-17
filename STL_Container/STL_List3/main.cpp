#include <list>
#include <iostream>

// 구조체
struct Item
{
	Item(int itemCode = 0, int price = 0)
		: itemCode(itemCode), price(price)
	{

	}
	int itemCode;
	int price;
};

//데이터 출력용 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "아이템 코드: " << item.itemCode << " , 가격 : " << item.price;
}

int main()
{
	//생성
	std::list<int> list1;
	list1.emplace_back(10);
	list1.emplace_back(20);
	list1.emplace_back(20);
	list1.emplace_back(30);
	list1.emplace_back(40);

	//출력
	for (const auto& value : list1)
	{
		std::cout << "list 1: " << value << std::endl;
	}

	std::cout << "remove 테스트 1 - 일반 데이터 삭제\n";
	list1.remove(20);

	//출력
	for (const auto& value : list1)
	{
		std::cout << "list 1: " << value << std::endl;
	}

	//포인터 저장 리스트
	std::list<Item*> itemList;
	Item* item1 = new Item(10, 100);
	itemList.emplace_back(item1);

	Item* item2 = new Item(20, 200);
	itemList.emplace_back(item2);

	Item* item3 = new Item(30, 300);
	itemList.emplace_back(item3);

	std::cout << "remove 테스트 2 - 포인터 객체 삭제\n";

	//item3 삭제
	itemList.remove(item3);

	//출력
	for (const auto& item : itemList)
	{
		std::cout << *item << std::endl; // 포인터가 가리키고 있는 값을 참조하기 위해 역참조 *item
	}

	//메모리 해제
	for (auto item : itemList)
	{
		delete item;
	}

	std::cin.get();
}