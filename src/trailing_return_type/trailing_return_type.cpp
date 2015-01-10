// munged from:
// Prata, Stephen; Prata Stephen(2011 - 10 - 18).C++ Primer Plus(6th Edition)
// (Developer's Library) (Kindle Locations 29980-29990). Pearson Education. Kindle Edition.

#include <iostream>

// weird. C++ standard library does not have constant for Pi.
// do this at compile-time:
// OUCH! not constexpr keyword NOT available in microsoft C++ 11. UGH.
// see: http://en.cppreference.com/w/cpp/language/constexpr
//constexpr double pi() {
//    // return std::atan(1) * 4;
//    return 3.4;
//}
const double PI = std::atan(1.0) * 4;

double f1(double d, int i) {
    return d * i;
}

auto f2(double d, int i) -> double {
    return d * i;
}

// The problem that's addressed here is that T1 and T2 are not in scope before
// the compiler reads the f3 parameter list, so any use of decltype has to come
// after the parameter list. The new syntax makes that possible:
template<typename T1, typename T2>
auto f3(const T1& t1, const T2& t2) -> decltype(t1 * t2) {
    const auto retval = t1 * t2;
    return retval;
}

int main() {

    // note: heed the /W4 compiler warnings...

    std::cout << "f1(PI, 2): " << f1(PI, 2) << std::endl;
    std::cout << "f1(2, PI): " << f1(2, PI) << std::endl;

    std::cout << "f2(PI, 2): " << f2(PI, 2) << std::endl;
    std::cout << "f2(2, PI): " << f2(2, PI) << std::endl;

    std::cout << "f3(PI, 2): " << f3(PI, 2) << std::endl;
    std::cout << "f3(2, PI): " << f3(2, PI) << std::endl;
}
