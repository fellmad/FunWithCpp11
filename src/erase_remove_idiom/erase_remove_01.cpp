// http://en.wikipedia.org/wiki/Erase-remove_idiom

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

auto is_odd(int i) -> bool
{
    return (i % 2) != 0;
}

void print(const std::vector <int> &vec)
{
    for (const auto &i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main()
{
    // initialises a vector that holds the numbers from 0-9.
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);
    print(v);

    // removes all elements with the value 5
    v.erase( std::remove( std::begin(v), std::end(v), 5 ), std::end(v) );
    print(v);

    // removes all odd numbers
    v.erase( std::remove_if(std::begin(v), std::end(v), is_odd), std::end(v) );
    print(v);
}