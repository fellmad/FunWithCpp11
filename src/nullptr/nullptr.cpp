// Meyers, Scott(2014 - 11 - 11).Effective Modern C++: 42 Specific Ways to 
// Improve Your Use of C++11 and C++14 (Kindle Locations 1778 - 1782).
// O'Reilly Media. Kindle Edition. 

#include <Windows.h>    // #define NULL 0
#include <iostream>

void f(int)
{
    std::cout << "int parm" << std::endl;
}

void f(bool)
{
    std::cout << "bool parm" << std::endl;
}

void f(void*)
{
    std::cout << "void pointer parm" << std::endl;
}

int main()
{
    f(NULL);
    f("");
    f(nullptr);

    // fun: 
    std::cout << typeid(nullptr).name() << std::endl;
    return 0;
}
