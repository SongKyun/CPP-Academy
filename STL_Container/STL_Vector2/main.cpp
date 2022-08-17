#include <vector>
#include <iostream>

int main()
{
	//���� �׽�Ʈ
	std::vector<int> vector1;
	vector1.reserve(10);

	vector1.emplace_back(20);
	vector1.emplace_back(30);

	std::cout << "���� �׽�Ʈ 1\n";

	auto iter = vector1.begin();
	vector1.insert(iter, 10);

	//���
	for (const auto& item : vector1)
	{
		std::cout << " vector: " << item << std::endl;
	}

	std::cout << "���� �׽�Ʈ2 \n";

	//�ι�° ��ġ�� 200�� 2�� ����
	iter = vector1.begin();
	vector1.insert(++iter, 2, 200);

	//���
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cout << "���� �׽�Ʈ3\n";
	//initialize_list�� �ʱ�ȭ
	std::vector<int> vector2({ 1000, 2000, 3000 });
	iter = vector1.begin();
	iter += 2; // ����° ��ġ
	//�ٸ� ���Ϳ� �ִ� ������ ����
	vector1.insert(iter, vector2.begin(), vector2.end());

	//���
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cout << "���� �׽�Ʈ4\n";
	iter = vector1.begin();
	iter += 3;
	vector1.insert(iter, { 500, 600 ,700 });

	//���
	for (const auto& item : vector1)
	{
		std::cout << "vector1: " << item << std::endl;
	}

	std::cin.get();

	// 
}