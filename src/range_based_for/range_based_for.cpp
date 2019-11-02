#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (const auto &el : vec)
    {
        os << el << std::endl;
    }
    return os;
}

int main()
{
    std::vector<std::string> words{
        "hello",
        "from",
        __FILE__,
        "msc version:",
        std::to_string(_MSC_VER),
        "msc full version:",
        std::to_string(_MSC_FULL_VER),
        "dude."};
    std::cout << words << std::endl;

    std::vector<int> numbers{-6, 3, 5, -22, 0};
    std::cout << numbers << std::endl;
}

// line 5: generic (templated) extraction operator
// line 6: could we have used a trailing return type?
// line 7: range-based for loop
//         prevent copy constructor by using a reference