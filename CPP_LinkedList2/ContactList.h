#pragma once

#include "Contact.h"

class ContactList
{
public:
	ContactList();
	~ContactList();

	void AddToHead(const std::wstring& name);
	void Print();
	void Insert(const std::wstring& name);
	void DeleteNode(const std::wstring& name);

private:
	Contact* head;
	size_t size;
};