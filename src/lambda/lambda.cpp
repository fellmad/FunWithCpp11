#include <iostream>
#include <string>

int main()
{
    [] {std::cout << "hello Lambda." << std::endl; }();

    auto stringresult1 = [] (const std::string& str) -> std::string {
        return "Hello from " + str;
    } ("a parm to a lambda");
    std::cout << "--- stringresult1: " << stringresult1 << std::endl;

    // same: trailing return type inferred:
    auto stringresult2 = [] (const std::string& str) {
        return "Hello from " + str;
    } ("another lambda parm");
    std::cout << "--- stringresult2: " << stringresult2 << std::endl;

    auto doubleFunction = [=] (double x) { return 2.0 * x; };
    auto doubleResult = doubleFunction(4.1);
    std::cout << "--- doubleFunction(4.1): " << doubleResult << std::endl;

    // q: why is doubleFuntion's TYPE double?
    // a: hint: cast the return expression as an int...hover...
}