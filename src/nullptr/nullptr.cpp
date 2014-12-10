// http://en.cppreference.com/w/cpp/types/nullptr_t

#include <cstddef>	// #define's NULL
#include <iostream>

void f(void*)
{
    std::cout << "Pointer to void overload\n";
}

void f(int* pi)
{
   std::cout << "Pointer to integer overload\n";
}
 
void f(double* pd)
{
   std::cout << "Pointer to double overload\n";
}
 
void f(std::nullptr_t nullp)
{
   std::cout << "null pointer overload\n";
}
 
int main()
{
    int* intPointer(nullptr);
    double* doublePointer{nullptr};
 
    f(intPointer);
    f(doublePointer);
    f(nullptr);  // would be ambiguous without void f(nullptr_t)
    f("");

    // fun: uncomment the next line...
    // f(NULL);

    class Robot {
        std::string name;
        int hight_in_micrometers;
    };

    auto robot1 = new Robot();
    delete robot1;
    robot1 = nullptr;
    delete robot1;
    delete robot1;
    delete robot1;
}