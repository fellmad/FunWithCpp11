#include <iostream>

int main() {
	int a {3};
	[&a] {int i = a; ++a;} ();
	std::cout << "a: " << a << std::endl;
}

// line 5: capture local variable a by reference.
// line 5: add the "callable operator" ()
