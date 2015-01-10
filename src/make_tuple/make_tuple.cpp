#include <iostream>
#include <string>
#include <tuple>

// old:
// typedef std::tuple <bool, std::string, float> CommonTuple;

// C++11: we're having FUN! (no ugly #typedef's):
using CommonTuple = std::tuple < bool, std::string, float > ;

CommonTuple f1() {
    CommonTuple tup {true, "string from f1", 1.234f};
    return tup;
}

auto f2() ->CommonTuple {
    // http://en.cppreference.com/w/cpp/utility/tuple/forward_as_tuple
    return std::forward_as_tuple(false, "f2 string", 0.0f);
}

CommonTuple f3() {
    bool aBool {false};
    std::string aString {"a string"};
    float floater {1.234f};
    const auto tup = std::make_tuple(aBool, aString, floater);
    return tup;
}

// implement extraction operator for CommonTuple:
std::ostream &operator << (std::ostream &os, CommonTuple tup) {
    os <<
        std::boolalpha <<
        std::get<0>(tup) << "; " <<
        std::get<1>(tup) << "; " <<
        std::get<2>(tup);
    return os;
}

int main() {

    auto result1 = f1();
    std::cout << result1 << std::endl;

    const auto result2 = f2();
    std::cout << result2 << std::endl;

    auto result3 = f3();
    std::cout << result3 << std::endl;

    std::cout << std::endl;
    std::cout << "type of result1: " << typeid(result1).name() << std::endl;
}