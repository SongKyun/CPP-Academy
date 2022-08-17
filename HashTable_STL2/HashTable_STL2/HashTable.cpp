#include "HashTable.h"

//Ű ���� �Լ�
int GenerateKey(const string& keyString)
{
	int key = 0;
	for (size_t ix = 0; ix < keyString.length(); ++ix)
	{
		//����ġ ���� ���.
		//key += keyString[ix] * (ix + 1);

		// JDK���� ����ϴ� ���
		key = key * 31 + keyString[ix];
	}
	return abs(key);
}

HashTable::HashTable()
{

}

HashTable::~HashTable()
{

}

bool HashTable::IsEmpty() const
{
	size_t sum = 0;
	for (size_t ix = 0; ix < hashCount; ++ix)
	{
		sum += table[ix].size();
	}
	return sum == 0;
}

void HashTable::Add(const string& key, const string& value)
{
	//�ؽ� ���ϱ�
	//��Ŷ ��ȣ = �ε���
	int bucketIndex = GenerateKey(key) % hashCount;

	//�� �߰�/������ ��ġ
	list<Entry>& position = table[bucketIndex];

	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		//������ �����Ͱ� �ִ��� �˻�.
		if (iter->first == key && iter->second == value)
		{
			//hashKey = true;
			cout << "�̹� ������ �����Ͱ� ����� �ֽ��ϴ�\n";
			return;
		}
	}

	//������ �����Ͱ� ������ �� �߰�
	position.emplace_back(Entry(key, value));

}

void HashTable::Delete(const string& key)
{
	//�ؽ� �� ���ϱ�
	int buckeIndex = GenerateKey(key) % hashCount;

	//��ġ ��������
	auto& position = table[buckeIndex];

	//�˻�
	for (auto iter = position.begin(); iter != position.end(); ++iter)
	{
		//������ �����͸� ã���� ����.
		if (iter->first == key)
		{
			position.erase(iter);
			cout << "�׸��� �����Ǿ����ϴ�.\n";

			return;
		}
	}
	//��ã�� ���
	cout << " �����͸� ã�� ���߽��ϴ�. \n";
}

HashTable::Entry HashTable::Find(const string& key)
{
	//�˻�
	int buckeIndex = GenerateKey(key) % hashCount;
	if (table[buckeIndex].size() == 0 )
	{
	cout << "�ش� Ű�� �����͸� ã�� ���߽��ϴ� \n";
	return Entry("", "");
	}

	//��ȸ
	for (auto iter = table[buckeIndex].begin(); iter != table[buckeIndex].end(); ++iter)
	{
		if (iter->first == key)
		{
			return *iter;
		}
	}
	cout << "�ش� Ű�� �����͸� ã�� ���߽��ϴ� \n";
	return Entry("","");
}

void HashTable::Print()
{
	for (int ix = 0; ix < hashCount; ++ix)
	{
		if (table[ix].size() == 0)
		{
			continue;
		}

		for (auto iterator = table[ix].begin(); iterator != table[ix].end(); ++iterator)
		{
			cout << "Key: " << iterator->first
				<< " Value: " << iterator->second << endl;
		}
	}
}

