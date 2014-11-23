#include <vector>
#include <iostream>
#include <iomanip>

int main()
{
    char c1 = 1.234e12;  // warning: C4244: 'initializing' : conversion from 'double' to 'char', possible loss of data
    c1 = 54321;  // warning C4305 : '=' : truncation from 'int' to 'char'

    //char c2 {3.456};    // error C2397: conversion from 'double' to 'char' requires a narrowing conversion
    //char c3 = {3.456};  // ditto

    char capitalLetter_A {65};  // ok; in range
    double d1 {3};              // ok; in range - convert int to double;

    using byte = unsigned char; // C++ does not have a 'byte' data type. (windows does...)

    // uniform initialization:
    std::vector <byte> bytes {9, 2, 255, 34, 'x', 4, 9};

    const auto& xPosition = std::find(bytes.cbegin(), bytes.cend(), 'x');
    bytes.insert(xPosition + 1, 'y');

    for (const auto& aByte : bytes) {
        const int& aNumericValue = aByte;   // ok; not narrowed
        std::cout << std::hex << std::setw(4) << aNumericValue << " " <<
            std::dec << std::setw(4) << aByte << std::endl;
    }

    return 0;
}