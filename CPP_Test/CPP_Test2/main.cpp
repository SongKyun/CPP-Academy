//-���簢���� ��Ÿ���� Rectagle Ŭ������ ���� ��Ÿ���� Circle Ŭ������ �����غ���.
//- �� Ŭ������ ���̸� ���ϴ� ��ɰ� �ѷ��� ���ϴ� ����� �����ؾ� �Ѵ�.
//- �Ʒ� main �Լ� ���ÿ� ��� ����� ������ Ŭ������ ������.

#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

int main()
{
	Rectangle rectangle(3, 4); // ���� ����
	std::cout << "���簢�� ����: " << rectangle.GetArea() << std::endl;
	std::cout << "���簢�� �ѷ�: " << rectangle.GetPerimeter() << std::endl;

	Circle circle(5); // ������
	std::cout << "���� ����: " << circle.GetArea() << std::endl;
	std::cout << "���� �ѷ�: " << circle.GetCircumference() << std::endl;

	std::cin.get();

}

// Rectangle, Circle / GetArea(), GetPerimeter(), GetCircumference()
// Circle.h, Rectangle.h