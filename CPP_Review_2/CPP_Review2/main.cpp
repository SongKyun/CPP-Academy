//#include <iostream>
//
//// Bit ��Ʈ
//int AttackItem = 1; //0001
//int DefenceItem = 2; // 0010
//int Portion = 4; // 0100
//int HealthPower = 8; // 1000
//
//int PlayerItem = 0;
//
//int main()
//{
//	PlayerItem = PlayerItem | AttackItem;
//	PlayerItem = PlayerItem | DefenceItem;
//
//	// �÷��̾ AttackItem�� ������ �ִ��� ����?
//	// ??
//	if ( (PlayerItem & AttackItem) == AttackItem )
//	{
//
//	}
//
//}
#include <iostream>


//#define VOID void // VOID > void �� �ؽ�Ʈ�� �ٲ�

#define LOG(x) std::cout << x << std::endl

int main()
{
	//������ ����
	int variable = 10;
	// ���� �տ� &�� ������ �� ������ �ּҸ� �о�´�.
	int* ptr = &variable;
	*ptr = 200;
	LOG(*ptr);
	LOG(variable);

	LOG(ptr);
	LOG(&variable);

	//�����Ҵ� -> ��(Heap) ������ �޸𸮸� Ȯ��(�Ҵ�)�ϴ� ����.
	// std::cout << sizeof(ptr) << std::endl;


}