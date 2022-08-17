//#include <iostream>
//
//// Bit 비트
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
//	// 플레이어가 AttackItem을 가지고 있는지 검출?
//	// ??
//	if ( (PlayerItem & AttackItem) == AttackItem )
//	{
//
//	}
//
//}
#include <iostream>


//#define VOID void // VOID > void 로 텍스트를 바꿈

#define LOG(x) std::cout << x << std::endl

int main()
{
	//포인터 선언
	int variable = 10;
	// 변수 앞에 &가 붙으면 그 변수의 주소를 읽어온다.
	int* ptr = &variable;
	*ptr = 200;
	LOG(*ptr);
	LOG(variable);

	LOG(ptr);
	LOG(&variable);

	//동적할당 -> 힙(Heap) 영역에 메모리를 확보(할당)하는 동작.
	// std::cout << sizeof(ptr) << std::endl;


}