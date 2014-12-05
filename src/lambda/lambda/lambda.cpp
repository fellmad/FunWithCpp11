#include <iostream>

int main()
{
    auto doubleFunction = [=] (double x) { return  2.0 * x; };
    auto doubleResult = doubleFunction(4.1);
    std::cout << "--- doubleFunction(4.1): " << doubleResult << std::endl;

    // q: why is doubleFuntion's TYPE double?
    // a: hint: cast the return expression as an int...


    return 0;
}