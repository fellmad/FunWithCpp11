#include <windows.h>
#include <tchar.h>
#include <string>
#include <iostream>

class A {
	std::string a;
	long long b;
};

class B : public A {};

int _tmain()
{
	auto a = A();
	std::cout << typeid(A).name() << std::endl;
	std::cout << typeid(a).name() << std::endl;

	const auto b = B();
	std::cout << typeid(B).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;

	std::cout << typeid(std::wstring).name() << std::endl;
	std::cout << typeid(std::cout).name() << std::endl;

	std::cout << std::endl << "Press any key. Do it.";
	getchar();

	return 0;
}