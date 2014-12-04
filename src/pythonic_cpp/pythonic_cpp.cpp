// http://preshing.com/20141202/cpp-has-become-more-pythonic/

#include <vector>
#include <iostream>
#include <tuple>

int main()
{
    // Literals
    // Python introduced binary literals in 2008. Now C++14 has them:
    // static const int primes = 0b10100000100010100010100010101100; // c++14 only!

    // Python also introduced raw string literals back in 1998. They’re
    // convenient when hardcoding a regular expression or a Windows path. C++11
    // added the same idea with a slightly different syntax:
    const char* path = R"(c:\this\string\has\backslashes)";

    // Range-Based For Loops
    // In Python, a for loop always iterates over a Python object:
    //  for x in myList:
    //      print(x)

    // Meanwhile, for nearly three decades, C++ supported only C-style for loops.
    // Finally, in C++11, range-based for loops were added:
    std::vector <int> ints {-3, 39, 12345, -45678};
    for (const auto& x : ints) {
        std::cout << x << std::endl;
    }

    // You can iterate over a std::vector or any class which implements the 
    // begin and end member functions – not unlike Python’s iterator protocol.
    // With range - based for loops, I often find myself wishing C++ had
    // Python’s xrange function built - in.


    // Auto
    // Python has always been a dynamically typed language. You don’t need to
    // declare variable types anywhere, since types are a property of the objects
    // themselves.
    //  x = "Hello world!"
    //  print(x)

    // C++, on the other hand, is not dynamically typed; it’s statically typed.
    // But since C++11 repurposed the auto keyword for type deduction, you
    // can write code that looks a lot like dynamic typing:
    auto x = "Hello world!";
    std::cout << x << std::endl;

    // When you call functions that are overloaded for several types, such as
    // std::ostream::operator<< or a template function, C++ resembles a
    // dynamically typed language even more. C++14 further fleshes out support
    // for the auto keyword, adding support for auto return values and auto
    // arguments to lambda functions.

    // Tuples
    // Python has had tuples pretty much since the beginning. They’re nice when
    // you need to package several values together, but don’t feel like naming
    // a class.
    //  triple = (5, 6, 7)
    //  print(triple[0])
    //
    // C++ added tuples to the standard library in C++11. The proposal even
    // mentions Python as an inspiration:
    auto triple = std::make_tuple(5, 6, 7);
    std::cout << std::get<0>(triple) << std::endl;

    // Python lets you unpack a tuple into separate variables:
    //  x, y, z = triple

    // You can do the same thing in C++ using std::tie:
    short i, j, k;
    std::tie(i, j, k) = triple;
    std::cout << "i, j, k: " << i << ", " << j << ", " << k << std::endl;
    
    // dlftodo: remainder of http://preshing.com/20141202/cpp-has-become-more-pythonic/
    return 0;
}
