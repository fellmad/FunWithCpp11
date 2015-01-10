#include <iostream>
#include <string>

int main() {
    const std::string name {"dude"};
    const std::string plural {"s"};
    [plural, &name] () {std::cout << "hello " << name << plural << std::endl;};
}

// hint: add the 'callable operator' line 7
// hint: or, give it a name, and then call it...