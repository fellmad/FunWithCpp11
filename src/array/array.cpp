// munged from: http://www.cplusplus.com/articles/EzywvCM9/
//
// std::array: a lean, mean stripped-down std::vector. not resizable.

#include <array>
#include <iostream>

int main()
{
    // naked c-style arrays:
    char carray1[] = "Abc"; // caution, an unseen '\0' is added to the end
    float carray2[] = { 0.2f, 33.33f };

    // C++11 std::arrays:
    std::array<char, 3> cpparray1{ {'A', 'b', 'c'} };
    std::array<float, 2> cpparray2{ {0.2f, 33.33f} };

    // observation 1: the size must be deducible at compile time
    // observation 2: the array cannot be resized
    // observation 3: the inner braces are due to the nature of initializer lists,
    // think of it as one list per template parameter

    // array test drive: the old versus the new

    std::cout << sizeof carray1 - 1 << std::endl;             // -1 because of the extra '\0'
    std::cout << sizeof carray2 / sizeof(float) << std::endl; // because number of elements != number of bytes

    std::cout << cpparray1.size() << std::endl;
    std::cout << cpparray2.size() << std::endl;

    // carray2[-5] = 0.1f; // compiles, but will crash at runtime

    try
    {
        cpparray2.at(-5) = 0.1f; // throws std::out_of_range exception
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// instead of sizeof arr / sizeof arr thing, use _countof in line 25