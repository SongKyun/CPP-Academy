#include <iostream>
#include <string>

int main()
{
	//문자열
	const char* testString = "test";
	//int score = 100;
	//"최종 점수는"

	std::string stdTestString = "test" + std::string("문자열") + " 입니다.";
	std::cout << stdTestString << std::endl;

	// wide character.
	const wchar_t* wideTestString = L"wchar_t test";
	std::wstring stdWideSTring = L"std::wstring test";

	std::wcout << stdWideSTring << std::endl;

	std::cout << "문장을 입력해 주세요\n";
	std::cin >> stdTestString;
	std::cout << "입력하신 문장은 \"" << stdTestString << "\" 입니다 \n";



	std::cout << "문장을 입력해 주세요\n";
	std::wcin >> stdWideSTring;
	std::wcout << "입력하신 문장은 \"" << stdWideSTring << "\" 입니다 \n";

	//문자열 조합(합치기)
	std::string str1 = "hello";
	auto str2 = "world";

	std::string str3 = str1 + " " + str2;
	std::cout << str3 << std::endl << std::endl;
	
	//검색
	auto pos = str3.find(" ");
		std::cout << " 검색된 위치는" << pos << "입니다. \n\n";


	// 문자열 자르기
	str1 = str3.substr(pos + 1);
	auto str4 = str3.substr(0, pos);

	std::cout << str1 << " " << str4 << std::endl;

	std::cout << "str[3]: " << str3[0] << std::endl;

	std::cin.get();
}