#include <iostream>

void Swap(int& number1, int& number2)
{
	int temp = number1;
	number1 = number2;
	number2 = temp;
}

int main()
{
	
	int number1 = 10;
	int number2 = 20;

	std::cout << "���� ��. number1: " << number1 << ", number2: " << number2 << std::endl;

	Swap(number1, number2);

	std::cout << "���� ��. number1: " << number1 << ", number2: " << number2 << std::endl;

	std::cin.get();
}

//- Call by Reference�� ����� int ���� �� ���� ���� ���� �ٲٴ� Swap�Լ��� �ۼ��غ���.
//- �Ʒ� main �Լ� ���ÿ� ���� ����� ������ �Լ��� �ۼ�����