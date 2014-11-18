#include <iostream>
#include <thread>
#include <string>

unsigned long long factorial(const unsigned long long currentNumber)  // C++11: 64-bit
{
    if (currentNumber <= 1) {
        return 1;
    }

    const auto result = currentNumber * factorial(currentNumber - 1);
    return result;
}

void sayHello(const std::string& message)
{
    std::cout << "hello from a c++ 11 thread dude." << std::endl;
    std::cout << message << std::endl;

    for (int factorialIndex(0); factorialIndex < 10000000; factorialIndex++) {
        const auto factorialNumber(30);
        const auto _64_bit_number = factorial(factorialNumber);
        // std::cout << "factorial of " << factorialNumber << " is " << _64_bit_number << std::endl;
    }

    //std::chrono::seconds sleepSecs(5);
    //std::cout
    //    << "thread " << std::this_thread::get_id() << " sleeping for "
    //    << sleepSecs.count() << " seconds." << std::endl;
    //std::this_thread::sleep_for(sleepSecs);
}

int main()
{
    std::cout.sync_with_stdio(true); // make std::cout thread-safe

    const auto concurrency = std::thread::hardware_concurrency();
    std::cout << "on this box, the number of hardware thread contexts is: " << concurrency << std::endl;
    std::cout << "main() thread id: " << std::this_thread::get_id() << std::endl;

    std::thread t1(sayHello, "yo: this is how you pass a parm!");
    const auto thisThreadID = t1.get_id();
    std::cout << "thread id " << thisThreadID << " launched." << std::endl;

    t1.join();
    std::cout << "back on the main thread - " << thisThreadID << std::endl;

    return 0;
}