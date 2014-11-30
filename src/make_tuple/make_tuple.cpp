#include <iostream>
#include <string>
#include <tuple>

// old:
// typedef std::tuple <bool, std::string, float> CommonTuple;

// C++11: we're having fun:
using CommonTuple = std::tuple < bool, std::string, float > ;

CommonTuple f1()
{
    CommonTuple tup {true, "string from f1", 1.234f};
    return tup;
}

CommonTuple f2()
{
    // http://en.cppreference.com/w/cpp/utility/tuple/forward_as_tuple
    return std::forward_as_tuple(false, "f2 string", 0.0f);
}

CommonTuple f3()
{
    bool aBool {false};
    std::string aString {"a string"};
    float floater {1.234f};
    const auto tup = std::make_tuple(aBool, aString, floater);
    return tup;
}

int main()
{
    auto result1 = f1();
    std::cout << typeid(result1).name() << std::endl;

    const auto result2 = f2();
    std::cout << typeid(result2).name() << std::endl;

    auto result3 = f3();
    std::cout << typeid(result3).name() << std::endl;
}