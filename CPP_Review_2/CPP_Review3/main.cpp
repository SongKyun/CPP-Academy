#include <iostream>

// ���۷����� ��� �����ʹ�.

// ����Լ�
#define Log(x) std::cout << x << std::endl
// Call by Value - Copy ���� -> ���� �����Ѵ�
// Call by Reference -> ���� -> �ּ� ����(4����Ʈ ����)
void Increment(int* a) // (int a)
{
	++(*a); //  ++a;
}
//a �� 1�� �ƴٰ� 2�� �ð� �״´�

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ���� ���� a�� b�� ���� �Լ� �ȿ����� ���� ��ü �ȴ�
// ��ǻ� ��ü�� ���� �ʰ�

int main()
{
	//// sizeof(�ڷ���, �����̸�);
	//int number = 10;

	////������
	//// null reference exception 
	//int* intPointer = &number; // nullptr; // 0

	//// ���۷��� (Reference - ���� - ���)
	//// �޸� �ּҸ� ���� (���)
	//int& intRef = number;
	//intRef = 200; // number 10�� ����Ǿ� �̾��µ� ���۷����� ���� ������ �� ���̴� ���̿��� 200�� ����ȴ�.
	//
	//Log(intRef); // #define Log(x) std::cout << x << std::endl; ��� ; �� �ߺ��Ǿ ���ش�
	//Log(number);

	//int number = 1; // ��� ����Ǿ� �ִ� �ּ�
	//Increment(&number); //(number); // (1) �̳� �������� ���� �����ؿ´�
	//Log(number);

	int a = 10;
	int b = 20;
	
	Swap(a, b);
	Log(a);
	Log(b);

	/*int temp = a;
		a = b;
		b = temp;*/
	// a<->b swap (��ȯ)



	std::cin.get();
}