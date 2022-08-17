#include "Program.h"	

int main()
{
	Program* program = new Program();

	program->InsertLoop();
	program->DeleteLoop();

	delete program;

	std::cin.get();
}