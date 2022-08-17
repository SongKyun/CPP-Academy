#include "ContactList.h"

ContactList::ContactList()
	: head(nullptr), size(0)
{
}

ContactList::~ContactList()
{
	Contact* current = head;
	Contact* deleteNode = nullptr;
	while (current != nullptr)
	{
		deleteNode = current;
		current = current->next;
		delete deleteNode;
		--size;
	}
}

void ContactList::AddToHead(const std::wstring& name)
{
	Contact* newContact = new Contact(name);
	if (head == nullptr)
	{
		head = newContact;
		size++;
		return;
	}

	newContact->next = head;
	head = newContact;
	size++;
}

void ContactList::Print()
{
	Contact* current = head;
	while (current != nullptr)
	{
		std::wcout << *current << std::endl;
		current = current->next;
	}
}

void ContactList::Insert(const std::wstring& name)
{
	Contact* newContact = new Contact(name);

	if (head == nullptr)
	{
		head = newContact;
		size++;
		return;
	}

	Contact* current = head;
	Contact* trail = nullptr;

	while (current != nullptr)
	{
		if (current->name >= newContact->name)
		{
			break;
		}

		trail = current;
		current = current->next;
	}

	if (current == head)
	{
		newContact->next = head;
		head = newContact;
		size++;
		return;
	}

	newContact->next = current;
	trail->next = newContact;
	size++;
}

void ContactList::DeleteNode(const std::wstring& name)
{
	if (head == nullptr)
	{
		std::wcout << "����Ʈ�� ��� ������ �� �����ϴ�.\n";
		return;
	}

	Contact* current = head;
	Contact* trail = nullptr;

	while (current != nullptr)
	{
		if (current->name == name)
		{
			break;
		}

		trail = current;
		current = current->next;
	}

	if (current == nullptr)
	{
		std::wcout << "�̸�: " << name << " ��(��) ã�� ���߽��ϴ�.\n";
		return;
	}

	if (head == current)
	{
		head = head->next;
		size--;
		return;
	}

	trail->next = current->next;
	size--;
}