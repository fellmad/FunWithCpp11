#include <vector>
#include <iostream>
#include <iomanip>

// compile with /EHsc, and /Fa to see .ASM output.

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

    for (const auto& the_byte : bytes) {
        const int& aNumericValue = the_byte;   // ok; not narrowed
        std::cout << std::hex << std::setw(4) << aNumericValue << " " <<
            std::dec << std::setw(4) << the_byte << std::endl;
    }

    {
        // we had this in our sdk samples:
        std::vector <byte> sendBytes;
        sendBytes.push_back(0x00);
        sendBytes.push_back(0xC0);
        sendBytes.push_back(0x00);
        sendBytes.push_back(0x00);
        sendBytes.push_back(0x12);

        // better; just like the C# sample:
        std::vector <byte> sendBytes2 {0x00, 0xC0, 0x00, 0x00, 0x12};
    }

    // any difference here? view .ASM:
    short y0 = -123;
    short y1 = {-123};
    short y2 {-123};
}