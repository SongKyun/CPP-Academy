#include <iostream>
#include <string>

int main()
{
	//���ڿ�
	const char* testString = "test";
	//int score = 100;
	//"���� ������"

	std::string stdTestString = "test" + std::string("���ڿ�") + " �Դϴ�.";
	std::cout << stdTestString << std::endl;

	// wide character.
	const wchar_t* wideTestString = L"wchar_t test";
	std::wstring stdWideSTring = L"std::wstring test";

	std::wcout << stdWideSTring << std::endl;

	std::cout << "������ �Է��� �ּ���\n";
	std::cin >> stdTestString;
	std::cout << "�Է��Ͻ� ������ \"" << stdTestString << "\" �Դϴ� \n";



	std::cout << "������ �Է��� �ּ���\n";
	std::wcin >> stdWideSTring;
	std::wcout << "�Է��Ͻ� ������ \"" << stdWideSTring << "\" �Դϴ� \n";

	//���ڿ� ����(��ġ��)
	std::string str1 = "hello";
	auto str2 = "world";

	std::string str3 = str1 + " " + str2;
	std::cout << str3 << std::endl << std::endl;
	
	//�˻�
	auto pos = str3.find(" ");
		std::cout << " �˻��� ��ġ��" << pos << "�Դϴ�. \n\n";


	// ���ڿ� �ڸ���
	str1 = str3.substr(pos + 1);
	auto str4 = str3.substr(0, pos);

	std::cout << str1 << " " << str4 << std::endl;

	std::cout << "str[3]: " << str3[0] << std::endl;

	std::cin.get();
}