//-계산기 기능을 가진 Calculator 클래스는 작성해보자.
//- 제공 함수는 덧셈 / 뺄셈 / 곱셈 / 나눗셈이다.
//- 연산을 할 때마다 어떤 연산을 몇 번 했는지 기록해야 한다.
//- 아래 실행 예시 코드와 실행 결과를 참고해 클래스를 설계하고 작성해보자.
//- 계산에 사용하는 자료형은 double로 한다.

#include <iostream>
#include "Calculator.h"

int main()
{
	Calculator calculator;

	std::cout << " 3 + 5 = " << calculator.Add(3, 5) << std::endl;
	std::cout << " 3 / 5 = " << calculator.Divide(3, 5) << std::endl;
	std::cout << " 12 - 4 = " << calculator.Subtract(12, 4) << std::endl;
	std::cout << " 12 * 4 = " << calculator.Muliply(12, 4) << std::endl;

	calculator.ShowOperationCount();

	std::cin.get();
}
// << 연산자 오버로딩
//