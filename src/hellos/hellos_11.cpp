#include <iostream>
#include <string>

auto getHello() -> const std::string {
    const auto& unused_stuff {-4.567e45};
    return "hello from C++ 11 dude.";
}

int main() {
    std::cout << getHello() << std::endl;
}

// line 4, 9: "Trailing Return Type":
// http://en.cppreference.com/w/cpp/language/function

// another tidbit: main() is special; you do not NEED to return anything; zero by default
