// C++ OOP ��ü ���� ���α׷���
// Object-Oriented-Programming
// Class - Data + Function

#include <list>
#include <iostream>

// ������ ����ü.
struct Item
{
	Item(int itemCode = 0, int price = 0)
		: itemCode(itemCode), price(price)
	{
	}

	int itemCode;
	int price;
};

// ������ ��¿� ������ �����ε�.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "������ �ڵ�: " << item.itemCode << ", ����: " << item.price;
}

// ���Ŀ� ����� �Լ� ��ü ����.
// �Լ� ��ü.
// Ŭ������ �Լ� �����ε��� �� ��ü.
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
	// ����Ʈ ����.
	std::list<Item> itemList;

	// �߰�.
	// �տ� �߰�.
	Item item1(1, 200);
	itemList.push_front(item1);
	Item item2(2, 1000);
	itemList.push_front(item2);

	// �ڿ� �߰�.
	Item item3(3, 3000);
	itemList.push_back(item3);
	Item item4(4, 4500);
	itemList.push_back(item4);

	// ���.
	// end() �ݺ��� ����.
	std::list<Item>::iterator iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// ��ȸ.
	//for (auto iter = itemList.begin(); iter != iterEnd; ++iter)
	for (std::list<Item>::iterator iter = itemList.begin();
		iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	// ����.
	// �� ������ ����.
	itemList.pop_front();

	// ������ �б�.
	auto frontItem = itemList.front();

	// ���.
	std::cout << frontItem << " , " << itemList.back() << std::endl;

	Item item6(6, 3000);
	itemList.push_back(item6);
	Item item5(5, 4500);
	itemList.push_back(item5);

	Item item8(8, 3000);
	itemList.push_back(item8);
	Item item7(7, 4500);
	itemList.push_back(item7);

	// ����.
	ItemLessComparer lessComparer;
	itemList.sort(lessComparer);

	std::cout << "===============================\n";

	// ���.
	// end() �ݺ��� ����.
	iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// ��ȸ.
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

	// ���.
	// end() �ݺ��� ����.
	iterEnd = itemList.end();
	//auto iterEnd = itemList.end();
	// ��ȸ.
	//for (auto iter = itemList.begin(); iter != iterEnd; ++iter)
	for (std::list<Item>::iterator iter = itemList.begin();
		iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	//����Ʈ ����.
	itemList.clear();
	auto count = itemList.size();
	std::cout << " ���� �ִ� ������ ���� : " << count << std::endl;

	std::cin.get();
}