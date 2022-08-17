#include <iostream>

// 레퍼런스는 사실 포인터다.

// 출력함수
#define Log(x) std::cout << x << std::endl
// Call by Value - Copy 복사 -> 값을 복사한다
// Call by Reference -> 참조 -> 주소 전달(4바이트 복사)
void Increment(int* a) // (int a)
{
	++(*a); //  ++a;
}
//a 가 1이 됐다가 2로 늘고 죽는다

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 전달 받은 a와 b의 값이 함수 안에서만 서로 교체 된다
// 사실상 교체가 되지 않고

int main()
{
	//// sizeof(자료형, 변수이름);
	//int number = 10;

	////포인터
	//// null reference exception 
	//int* intPointer = &number; // nullptr; // 0

	//// 레퍼런스 (Reference - 참조 - 사용)
	//// 메모리 주소를 참조 (사용)
	//int& intRef = number;
	//intRef = 200; // number 10이 저장되어 이었는데 레퍼런스는 같은 공간에 또 붙이는 것이여서 200이 저장된다.
	//
	//Log(intRef); // #define Log(x) std::cout << x << std::endl; 출력 ; 은 중복되어서 빼준다
	//Log(number);

	//int number = 1; // 어디 저장되어 있는 주소
	//Increment(&number); //(number); // (1) 이나 마찬가지 값을 복사해온다
	//Log(number);

	int a = 10;
	int b = 20;
	
	Swap(a, b);
	Log(a);
	Log(b);

	/*int temp = a;
		a = b;
		b = temp;*/
	// a<->b swap (교환)



	std::cin.get();
}