#include <string>
#include <iostream>

class Printer {

	// "non-static data member with initializer (C++11)"
    int _jobCount = 3;
    std::string _name = "xps card printer";

    // i *sure wish* we could do this with strings:
    static const unsigned short _maxJobs = 100;

public:
    void Dump() {
        std::cout << _name << " job count: " << _jobCount << std::endl;
    }
};

int main() {
    Printer p;
    p.Dump();
}