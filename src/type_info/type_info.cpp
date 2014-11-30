#include <string>
#include <iostream>

auto multiply_two_ints(const int& a, const int& b) -> int
{
	const int result = a * b;
	return result;
}

class A {
	std::string a;
	long long b;
};

class B : public A {};

int main()
{
	auto a = A();

	std::cout << typeid(A).name() << std::endl;
	std::cout << typeid(a).name() << std::endl;

	const auto b = B();
	std::cout << typeid(B).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;

	std::cout << typeid(std::wstring).name() << std::endl;
	std::cout << typeid(std::cout).name() << std::endl;

	std::cout << typeid(multiply_two_ints).name() << std::endl;
 
 	std::cout << std::endl << "Press any key. Do it.";
	getchar();

	return 0;
}