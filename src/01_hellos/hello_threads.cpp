#include <iostream>
#include <thread>
#include <tchar.h>

void sayHello()
{
    std::cout << "hello from a c++ 11 thread dude." << std::endl;
    std::chrono::seconds sleepSecs(5);
    std::cout
        << "thread " << std::this_thread::get_id() << " sleeping for "
        << sleepSecs.count() << " seconds." << std::endl;
    std::this_thread::sleep_for(sleepSecs);
}

int main()
{
    std::cout.sync_with_stdio(true); // make sure cout is thread-safe

    const auto concureency = std::thread::hardware_concurrency();
    std::cout << "on this box, the number of hardware thread contexts is: " << concureency << std::endl;
    std::cout << "main() thread id: " << std::this_thread::get_id() << std::endl;

    std::thread t1(sayHello);
    std::cout << "thread id " << t1.get_id() << " launched." << std::endl;

    t1.join();
    std::cout << "we're back on the main thread. press any key, dude." << std::endl;
    ::_gettchar();

    return 0;
}