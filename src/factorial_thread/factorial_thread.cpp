#include <iostream>
#include <thread>
#include <string>

unsigned long long factorial(const unsigned long long currentNumber)  // C++11: 64-bit
{
    if (currentNumber <= 1)
    {
        return 1;
    }

    const auto result = currentNumber * factorial(currentNumber - 1);
    return result;
}

void sayHello(const int number, const short factorial_count)
{
    std::cout << "hello from a c++ 11 thread dude." << std::endl;
    std::cout << "getting factorial of " << number
              << " " << factorial_count << " times." << std::endl;

    auto factorial_result = factorial(number);
    for (int factorialIndex(0); factorialIndex < 10000000; factorialIndex++) {
        factorial_result = factorial(number);
    }
    std::cout << "factorial of " << number << " is " << factorial_result << std::endl;
}

int main()
{
    std::cout.sync_with_stdio(true); // make std::cout thread-safe

    const auto concurrency = std::thread::hardware_concurrency();
    std::cout << "on this box, the number of hardware thread contexts is: " << concurrency << std::endl;
    std::cout << "main() thread id: " << std::this_thread::get_id() << std::endl;

    std::thread hello_thread(sayHello, 40, 50);
    const auto thisThreadID = hello_thread.get_id();
    std::cout << "thread id " << thisThreadID << " launched." << std::endl;

    hello_thread.join();
    std::cout << "back on the main thread - " << thisThreadID << std::endl;
}