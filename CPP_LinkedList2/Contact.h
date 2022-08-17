#pragma once

#include <iostream>
#include <string>

class Contact
{
	friend std::wostream& operator<<(std::wostream& os, const Contact& contact);
	friend class ContactList;

public:
	Contact(const std::wstring& name);

private:
	std::wstring name;
	Contact* next;
};