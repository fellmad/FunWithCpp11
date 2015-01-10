#include <iostream>

int main() {
	int a {3};
	auto f = [&a] {
		int i = a;
		++a;
		std::cout << "line: " << __LINE__ << " lam i, a: " << i << ", " << a << std::endl;
	};
	std::cout << "line: " << __LINE__ << " a: " << a << std::endl;
	std::cout << "line: " << __LINE__ << " " << typeid(f).name() << std::endl;
	f;
	f();
	std::cout << "line: " << __LINE__ << " a: " << a << std::endl;
}

// line 5: assign the lambda expression to the variable f
// line 5: capture local variable a by reference
// line 12: ok; just a normal C++ expression (a lambda expression)
// line 13: add the callable operator (), and call it
