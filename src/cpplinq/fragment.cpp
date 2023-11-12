// http://www.drdobbs.com/cpp/linq-like-list-manipulation-in-c/240166882

#include "cpplinq.hpp"
#include <iostream>

void computes_a_sum()
{
    using namespace cpplinq;

    int ints[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 4 };

    auto result = from_array(ints)
        >> where([](int i) {return i % 2 == 0; })  // Keep only even numbers
        >> sum()                                    // Sum remaining numbers
        ;

    std::cout << "result: " << result << std::endl;
}

int main()
{
    computes_a_sum();
}