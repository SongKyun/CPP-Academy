#include <iostream>
#include "Hashtable.h"

int main()
{
	//�ؽ� ���̺� ����
	Hashtable table;

	//������ �߰�
	table.Add("Ronnie", " 010-123456789");
	table.Add("Kevin", " 010-123474789");
	table.Add("Baker", " 010-123457789");
	table.Add("Taejun", " 010-125556789");
	table.Add("Ronnie", " 010-123456689");

	//���
	table.Print();
	
	//�˻�
	auto find = table.Find("Ronnie");
	if (find.value.size() > 0)
	{
		std::cout << "�˻� ���: " << find.key << " , " << find.value << std::endl;
	}

	//����
	table.Delete("Ronnie");
	table.Delete("Kevin");

	// ���
	table.Print();

	std::cin.get();

}