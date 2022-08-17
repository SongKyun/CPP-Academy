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

	std::cout << "변경 전. number1: " << number1 << ", number2: " << number2 << std::endl;

	Swap(number1, number2);

	std::cout << "변경 후. number1: " << number1 << ", number2: " << number2 << std::endl;

	std::cin.get();
}

//- Call by Reference를 사용해 int 변수 두 개의 값을 서로 바꾸는 Swap함수를 작성해보자.
//- 아래 main 함수 예시와 실행 결과를 참고해 함수를 작성하자