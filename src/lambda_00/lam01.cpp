#include <iostream>

int main() {
	int a {3};
	[a] {int i = a;};
	std::cout << "a: " << a << std::endl;
}

// line 5: capture local variable a by value
// line 5: lambda expression. (haven't called it yet!)
// what about 'i' outside the lambda?