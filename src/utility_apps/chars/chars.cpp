#include <iostream>
#include <iomanip>

void output_a_line(const unsigned short& val)
{
    std::cout << std::setw(4);
    std::cout << std::dec << val << " ";
    std::cout << std::setw(4);
    std::cout << std::hex << val << " ";
    std::cout << std::setw(4);
    std::cout << (char) val << std::endl;
}

int main()
{
    for (unsigned short val = 0; val <= 255; val++) {
        output_a_line(val);
    }
    return 0;
}