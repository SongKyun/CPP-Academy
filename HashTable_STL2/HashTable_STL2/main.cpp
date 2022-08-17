#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
	// �ؽ� ���̺� ����.
	HashTable table;

	// ������ �߰�.
	table.Add("Ronnie", "010-12345678");
	table.Add("Kevin", "010-32979287");
	table.Add("Baker", "010-29871982");
	table.Add("Taejun", "010-39487298");

	// ���.
	table.Print();

	// �˻�.
	auto find = table.Find("Ronnie");
	if (find.first.size() > 0)
	{
		cout << "�˻� ���: " << find.first << " , " << find.second << endl;
	}

	// ����.
	table.Delete("Ronnie");

	table.Print();

	cin.get();
}