#include <iostream>
#include <thread>

void sayHello()
{
	std::cout << "hello from a c++ 11 thread dude." << std::endl;
}

int main()
{
	std::cout.sync_with_stdio(true); // Make sure cout is thread-safe

	std::thread t1(sayHello);
	t1.join();

	return 0;
}