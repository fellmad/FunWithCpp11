#include <iostream>
#include <thread>
#include <string>

void sayHello(std::string const& message, const short sleep_for_this_many_seconds) {
    const std::chrono::seconds sleepSecs(sleep_for_this_many_seconds);
    std::cout
        << "thread " << std::this_thread::get_id() << " sleeping for "
        << sleepSecs.count() << " seconds." << std::endl
        << "message: " << message << std::endl;

    std::this_thread::sleep_for(sleepSecs);
}

int main()
{
    std::cout.sync_with_stdio(true); // make std::cout thread-safe

    const auto concurrency = std::thread::hardware_concurrency();

    std::cout << "there are " << concurrency << " hardware thread contexts on this box." << std::endl;

    std::cout << "main() thread id: " << std::this_thread::get_id() << std::endl;

    std::thread t1(sayHello, "yo: this is how you pass a parm!", 5);

    const auto thisThreadID = t1.get_id();

    std::cout << "thread id " << thisThreadID << " launched." << std::endl;

    t1.join();

    std::cout << "back on the main thread - " << thisThreadID << std::endl;
}