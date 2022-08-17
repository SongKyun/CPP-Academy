#include <iostream>
void Print(const char* log)

{

	std::cout << log << std::endl;


}
void Print(double log)

{

	std::cout << log << std::endl;

}

void Print(int log)

{

	std::cout << log << std::endl;

}
int main()
{

	Print("Hello World");
	Print();

		int testNumber = 5;
	bool condition = testNumber == 5;
	if (condition == true)
	{
		Print("Condition is matched");
	}
}