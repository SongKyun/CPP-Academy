#include "ContactList.h"

using namespace std;

int main()
{
	ContactList* list = new ContactList();

	wstring name;

	while (true)
	{
		wcout << "추가할 연락처의 이름을 입력해주세요(종료는 q)\n";

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
		wcout << "삭제할 연락처의 이름을 입력해주세요(종료는 q)\n";

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