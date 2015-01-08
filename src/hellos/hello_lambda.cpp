#include <iostream>
#include <string>

int main() {
    const std::string name {"dude"};
    [&] () {std::cout << "hello " << name << std::endl;};
}

// hint: add the 'callable operator'..
// hint: give it a name, and then call it...