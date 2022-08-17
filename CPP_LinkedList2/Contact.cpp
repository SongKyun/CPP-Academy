#include "Contact.h"

using std::wstring;
using std::wostream;

Contact::Contact(const wstring& name)
	: name(name), next(nullptr)
{
}

wostream& operator<<(wostream& os, const Contact& contact)
{
	return os << "Name: " << contact.name;
}