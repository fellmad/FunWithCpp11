#include <iostream>

int main() {
	int a {3};
	[&a] {int i = a; a = 4;} ();
	std::cout << "a: " << a << std::endl;
}