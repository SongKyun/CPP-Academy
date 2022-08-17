#include "Program.h"

void Program::InsertLoop(ContactList** list)
{
	std::wstring name;

	while (true)
	{
		std::wcout << "�߰��� ����ó�� �̸��� �Է��ϼ���(����� q)\n";

		std::wcin >> name;

		if (name == L"q" || name == L"Q")
		{
			break;
		}

		(*list)->Insert(name);
		(*list)->Print();
	}
}

void Program::DeleteLoop(ContactList** list)
{
	std::wstring name;

	while (true)
	{
		std::wcout << "������ ����ó�� �̸��� �Է��ϼ���(����� q)\n";

		std::wcin >> name;

		if (name == L"q" || name == L"Q")
		{
			break;
		}

		(*list)->DeleteNode(name);
		(*list)->Print();
	}
}