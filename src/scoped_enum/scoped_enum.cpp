// munged from: http://en.cppreference.com/w/cpp/language/enum

#include <iostream>

// legacy C/C++ enum ("unscoped enum")
// color may be red (0), yellow (1), green (20), or blue (21)
enum color {
    red,
    yellow,
    green = 20,
    blue
};

// C++ scoped enum
// altitude may be altitude::high or altitude::low
enum class altitude : char {
    high = 'h',
    low  = 'l', // C++11 now officially allows the extra comma
};

// the constant d is 0, the constant e is 1, the constant f is 3
enum { d, e, f = e + 2 };

//enumeration types (both scoped and unscoped) can have overloaded operators
std::ostream &operator << (std::ostream &os, color c) {
    switch (c) {
    case red    : os << "red"; break;
    case yellow : os << "yellow"; break;
    case green  : os << "green"; break;
    case blue   : os << "blue"; break;
    default : os.setstate(std::ios_base::failbit);
    }
    return os;
}

// provide the C++ extraction operator for type altitude
std::ostream &operator << (std::ostream &os, altitude al) {
    return os << static_cast <char> (al);
}

int main() {

    color col = red;
    const altitude a {altitude::low};
    const auto& high_altitude = altitude::high;

    std::cout
        << "col           = " << col << std::endl
        << "a             = " << a << std::endl
        << "f             = " << f << std::endl
        << "high_altitude = " << high_altitude << std::endl
        ;
}

/*

C++98-style enums are now known as unscoped enums.

Enumerators of scoped enums are visible only within the enum. They convert to
other types only with a cast.

Both scoped and unscoped enums support specification of the underlying type. The
default underlying type for scoped enums is int. Unscoped enums have no default
underlying type.

Scoped enums may always be forward-declared. Unscoped enums may be forward-
declared only if their declaration specifies an underlying type.

Meyers, Scott (2014-11-11). Effective Modern C++: 42 Specific Ways to Improve
Your Use of C++11 and C++14 (Kindle Locations 2230-2234). O'Reilly Media. Kindle
Edition.

*/
