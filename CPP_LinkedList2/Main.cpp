#include "ContactList.h"

using namespace std;

int main()
{
	ContactList* list = new ContactList();

	wstring name;

	while (true)
	{
		wcout << "�߰��� ����ó�� �̸��� �Է����ּ���(����� q)\n";

		wcin >> name;

		if (name == L"q" || name == L"Q")
		{
			break;
		}

		//list->AddToHead(name);
		list->Insert(name);
		list->Print();
	}

	while (true)
	{
		wcout << "������ ����ó�� �̸��� �Է����ּ���(����� q)\n";

		wcin >> name;

		if (name == L"q" || name == L"Q")
		{
			break;
		}

		//list->AddToHead(name);
		list->DeleteNode(name);
		list->Print();
	}

	list->Print();

	delete list;
	std::cin.get();
}