//-직사각형을 나타내는 Rectagle 클래스와 원을 나타내는 Circle 클래스를 설계해보자.
//- 두 클래스는 넓이를 구하는 기능과 둘레를 구하는 기능을 제공해야 한다.
//- 아래 main 함수 예시와 출력 결과를 참고해 클래스를 만들어보자.

#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	Rectangle rectangle(3, 4); // 가로 세로
	std::cout << "직사각형 면적: " << rectangle.GetArea() << std::endl;
	std::cout << "직사각형 둘레: " << rectangle.GetPerimeter() << std::endl;

	Circle circle(5); // 반지름
	std::cout << "원의 면적: " << circle.GetArea() << std::endl;
	std::cout << "원의 둘레: " << circle.GetCircumference() << std::endl;

	std::cin.get();

}

// Rectangle, Circle / GetArea(), GetPerimeter(), GetCircumference()
// Circle.h, Rectangle.h