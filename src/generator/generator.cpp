// https://en.wikipedia.org/wiki/Generator_(computer_programming)

/*
Moreover, C++11 allows foreach loops to be applied to any class that provides
the begin and end functions. It's then possible to write generator-like classes
by defining both the iterable methods (begin and end) and the iterator methods
(operator!=, operator++ and operator*) in the same class. For example, it is
possible to write the following program:
*/

/*
dlf note: terminology: it's not a foreach loop - it's a "range-based for loop"
http://en.cppreference.com/w/cpp/language/range-for
std::for_each applies a function to each item in a collection.
*/

#include <iostream>

class range {
private:
    int last;
    int iter;

public:
    range(int end) :
        last(end),
        iter(0)
    {}

    // Iterable functions
    const range& begin() const
    {
        return *this;
    }
    const range& end() const
    {
        return *this;
    }

    // Iterator functions
    bool operator!=(const range&) const
    {
        return iter < last;
    }
    void operator++()
    {
        ++iter;
    }
    int operator*() const
    {
        return iter;
    }
};

int main()
{
    for (const auto& number : range(10)) {
        std::cout << number << std::endl;
    }
}