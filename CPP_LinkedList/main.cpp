#include <iostream>
#include "LinkedList.h"
#include <string>

int main()
{
	// ����Ʈ ����
	LinkedList* list = new LinkedList();
	
	// �ֿܼ��� �Է� �ޱ� ���� ����
	std::string input; 

	//���� ����
	// 1. Ż��(����)���Ǻ��� �����ϱ�
	while (true)
	{
		std::cout << "�߰��� �����͸� �Է����ּ���(����� q)\n";

		std::cin >> input;

		if (input == "q" || input == "Q")
		{
			break;
		}

		//������ �߰�. std::stoi() -> ���ڿ��� ���ڷ� ��ȯ
		list->Insert(std::stoi(input));

		list->Print();
		
	}

	// ���ѷ���.
	// ������ ������ �Է� �޾� ó��

	input = ""; // ���� �ʱ�ȭ
	while (true)
	{
		std::cout << "������ �����͸� �Է����ּ���(�����q)\n";

		std::cin >> input;

		if (input == "q" || input == "Q")
		{
			break;
		}

		list->DeleteDate(std::stoi(input));

		list->Print();
	}
	
	// ���.
	list->Print();

	delete list;

	std::cin.get();
}