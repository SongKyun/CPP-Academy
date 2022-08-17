#include "Hashtable.h"
//�ؽ� �Լ�
int GenerateKey(const std::string& keyString)
{
	int key = 0;
	for (size_t ix = 0; ix < keyString.length(); ++ix)
	{
		// ����ġ ���� ���
		//key += keyString[ix] * (ix + 1);

		//JDK���� ����ϴ� �������
		key = key * 31 + keyString[ix];
	}
	//���밪 ���ϱ�
	return std::abs(key);
}


// h/cpp ��ȯ ����Ű ctrl + k > ctrl + o
Hashtable::Hashtable()
{
}

Hashtable::~Hashtable()
{
}
//�ؽ� ���̺��� ������� Ȯ��
bool Hashtable::IsEmpty() const
{
	size_t sum = 0;
	// table -> ��ũ�帮��Ʈ�� �迭.
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		sum += table[ix].Count();

		//sum = sum + table[ix].Count();
	}

	return sum == 0;
}

//������ �߰�.
void Hashtable::Add(const std::string& key, const std::string& value)
{
	// �ؽ� ���� ��, ��Ŷ �ε��� ���ϱ�.
	int bucketIndex = GenerateKey(key) % bucketCount;

	//�� �� ���� �ε����� ��ġ�� ��ũ�� ����Ʈ�� ����
	auto& position = table[bucketIndex];

	//�̹� ������ Ű�� �����Ͱ� ����� �ִ��� Ȯ�� (�ߺ�Ȯ��)
	for (size_t ix = 0; ix < position.Count(); ++ix)
	{
		//f12 / Ctrl + -
		if (position[ix]->data.key == key)
		{
			std::cout << "�̹� ������ Ű�� �����Ͱ� ����� �ֽ��ϴ�\n";
			return;
		}
	}

	//�ߺ��� �����Ͱ� ������ ������ �߰�
	position.PushLast(Entry(key, value));
}

void Hashtable::Delete(const std::string& key)
{
	//�ؽ� ���� ��, ��Ŷ �ε��� ���ϱ�
	int bucketIndex = GenerateKey(key) % bucketCount;
	//�ش� �ε����� ��ũ�帮��Ʈ�� ����
	auto& position = table[bucketIndex];

	//��ũ�帮��Ʈ�� ����� �����Ϳ��� ���޹��� Ű�� �����Ͱ� �ִ��� Ȯ��
	//ã�� ��� -> ����

	for (size_t ix = 0; ix < position.Count(); ++ix)
	{
		position.Delete(position[ix]->data);
		std::cout << "�׸��� �����Ǿ����ϴ�.\n";

		return;
	}
}

Hashtable::Entry Hashtable::Find(const std::string& key)
{
	//�ؽ� ���� �� , ��Ŷ �ε��� ���ϱ�
	int bucketIndex = GenerateKey(key) % bucketCount;

	if (table[bucketIndex].Count() == 0)
	{
		std::cout << "�ش� Ű�� �����͸� ã�� ���߽��ϴ� \n";
		return Entry("", "");
	}

	for (size_t ix = 0; ix < table[bucketIndex].Count(); ++ix)
	{
		if (table[bucketIndex][ix]->data.key == key)
		{
			//�˻� �����ϸ� �ش� ������ ��ȯ
			return table[bucketIndex][ix]->data;
		}
	}
	std::cout << "�ش� Ű�� �����͸� ã�� ���߽��ϴ�\n";
	return Entry();
}

void Hashtable::Print()
{
	//�迭 ��ȸ
	for (size_t ix = 0; ix < bucketCount; ++ix)
	{
		// ��ũ�� ����Ʈ�� ������� �ǳʶٱ�
		if (table[ix].Count() == 0)
		{
			continue;
		}

		// ������ ���
		for (size_t jx = 0; jx < table[ix].Count(); ++jx)
		{
			std::cout << "Ű: " << table[ix][jx]->data.key
				<< "��: " << table[ix][jx]->data.value << std::endl;
		}
	}
}
