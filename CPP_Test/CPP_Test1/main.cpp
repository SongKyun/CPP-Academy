//-���� ����� ���� Calculator Ŭ������ �ۼ��غ���.
//- ���� �Լ��� ���� / ���� / ���� / �������̴�.
//- ������ �� ������ � ������ �� �� �ߴ��� ����ؾ� �Ѵ�.
//- �Ʒ� ���� ���� �ڵ�� ���� ����� ������ Ŭ������ �����ϰ� �ۼ��غ���.
//- ��꿡 ����ϴ� �ڷ����� double�� �Ѵ�.

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
// << ������ �����ε�
//