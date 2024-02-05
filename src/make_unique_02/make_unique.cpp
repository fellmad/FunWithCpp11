// stolen from: http://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>
#include <utility>

class ThreeIntVector {
    int x, y, z;

public:
    ThreeIntVector() : x(0), y(0), z(0)
    {}

    ThreeIntVector(int x, int y, int z) : x(x), y(y), z(z)
    {}

    friend std::ostream& operator << (std::ostream& os, ThreeIntVector& v)
    {
        return os << '{' << "x:" << v.x << " y:" << v.y << " z:" << v.z << '}';
    }
};

int main()
{
    // Use the default constructor.
    std::unique_ptr<ThreeIntVector> v1 = std::make_unique<ThreeIntVector>();

    // Use the constructor that matches these arguments
    std::unique_ptr<ThreeIntVector> v2 = std::make_unique<ThreeIntVector>(0, 1, 2);

    // Create a unique_ptr to an array of 5 elements
    std::unique_ptr<ThreeIntVector[]> v3 = std::make_unique<ThreeIntVector[]>(5);

    std::cout
        << "make_unique<Vec3>():      " << *v1 << '\n'
        << "make_unique<Vec3>(0,1,2): " << *v2 << '\n'
        << "make_unique<Vec3[]>(5):   " << '\n';

    for (int i = 0; i < 5; i++) {
        std::cout << "     " << v3[i] << '\n';
    }
}

// line 15: how does compiler distinguish between parm and member var?
// line 15: should use references in parms to avoid copy constructor