#include <iostream>
#include <string>
#include <tuple>

int main() {
    int a = 1;
    std::string s = "a string";
    float f = 3.0f;
    auto tie1 = std::tie(a, s, f);
    auto tuple1 = std::make_tuple("a string", 1, 2.0f);
}