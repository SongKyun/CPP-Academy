#include <list>
#include <iostream>

int main()
{
	//����

	//����
	std::list<int> list1;

	list1.push_back(20);
	list1.push_back(30);

	std::cout << "���� �׽�Ʈ1 : " << std::endl;

	//ù ���� ��ġ�� ����
	std::list<int>::iterator iter = list1.begin();
	list1.insert(iter, 100);

	//���
	for (auto& item : list1)
	{
		std::cout << "list1: " << item << std::endl;
	}

	std::cout << "���� �׽�Ʈ 2" << std::endl;

	// �� ��° ��ġ�� 200�� 2�� ����
	iter = list1.begin();
	++iter;
	list1.insert(iter, 2, 200);
	//���
	for (auto& item : list1)
	{
		std::cout << "list 1: " << item << std::endl;
	}

	//

	std::cout << "���� �׽�Ʈ 3 " << std::endl;

	std::list<int> list2;
	list2.emplace_back(1000); // push �� �Լ��� 2���ε� �����ؼ� �޸𸮿� ���簡 �Ͼ�µ� emplace�� �Լ��� 1�����̶� �޸� �鿡�� �� ����
	list2.push_back(2000);
	list2.push_back(3000);

	//�� ��° ��ġ�� list2�� ��� ������ ����
	iter = list1.begin();
	++iter;
	list1.insert(iter, list2.begin(), list2.end());

	//���
	for (auto& item : list1)
	{
		std::cout << "list 1: " << item << std::endl;
	}

	std::cin.get();
}