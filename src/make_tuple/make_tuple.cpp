#include <iostream>
#include <string>
#include <tuple>

typedef std::tuple <bool, std::string, float> CommonTuple;

CommonTuple f1() {
    CommonTuple tup {true, "string from f1", 1.234f};
    return tup;
}

CommonTuple f2() {
  return std::forward_as_tuple(false, "f2 string", 0.0f);
}

int main()
{

    auto result1 = f1();
    std::cout << typeid(result1).name() << std::endl;

    auto result2 = f2();
    std::cout << typeid(result2).name() << std::endl;
}