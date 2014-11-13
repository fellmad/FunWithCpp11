#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec) {
        os << el << ' ';
    }
    return os;
}

int main()
{
    std::vector <std::string> words = {
        "hello",
        "from",
        __FILE__,
        "msc version:",
        std::to_string(_MSC_VER),
        "msc full version:",
        std::to_string(_MSC_FULL_VER),
        "dude."
    };

    std::cout << words << std::endl;
}