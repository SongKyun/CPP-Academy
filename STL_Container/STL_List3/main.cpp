#include <list>
#include <iostream>

// ����ü
struct Item
{
	Item(int itemCode = 0, int price = 0)
		: itemCode(itemCode), price(price)
	{

	}
	int itemCode;
	int price;
};

//������ ��¿� ������ �����ε�
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "������ �ڵ�: " << item.itemCode << " , ���� : " << item.price;
}

int main()
{
	//����
	std::list<int> list1;
	list1.emplace_back(10);
	list1.emplace_back(20);
	list1.emplace_back(20);
	list1.emplace_back(30);
	list1.emplace_back(40);

	//���
	for (const auto& value : list1)
	{
		std::cout << "list 1: " << value << std::endl;
	}

	std::cout << "remove �׽�Ʈ 1 - �Ϲ� ������ ����\n";
	list1.remove(20);

	//���
	for (const auto& value : list1)
	{
		std::cout << "list 1: " << value << std::endl;
	}

	//������ ���� ����Ʈ
	std::list<Item*> itemList;
	Item* item1 = new Item(10, 100);
	itemList.emplace_back(item1);

	Item* item2 = new Item(20, 200);
	itemList.emplace_back(item2);

	Item* item3 = new Item(30, 300);
	itemList.emplace_back(item3);

	std::cout << "remove �׽�Ʈ 2 - ������ ��ü ����\n";

	//item3 ����
	itemList.remove(item3);

	//���
	for (const auto& item : itemList)
	{
		std::cout << *item << std::endl; // �����Ͱ� ����Ű�� �ִ� ���� �����ϱ� ���� ������ *item
	}

	//�޸� ����
	for (auto item : itemList)
	{
		delete item;
	}

	std::cin.get();
}