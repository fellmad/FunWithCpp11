#include <iostream>

auto main() -> int
{
    std::wcout << L"hello from C++ 11 dude." << std::endl;
}

// line 3: "Trailing Return Type":
// http://en.cppreference.com/w/cpp/language/function

// line 3: yes; it's FUN and COOL - but NOT allowed in main() in C++14 (!)
// http://en.cppreference.com/w/cpp/language/main_function

// another tidbit: main() is special; you do not NEED to return anything.