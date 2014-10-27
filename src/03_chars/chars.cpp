#include "stdafx.h"
#include <iostream>
#include <iomanip>

int _tmain(int /*argc*/, _TCHAR* /*argv*/[], _TCHAR* envp[])
{
    for (short b = 0; b < 256; b++) {
        std::cout << std::setw(4);
        std::cout << std::dec << b << " ";
        std::cout << std::setw(4);
        std::cout << std::hex << b << " ";
        std::cout << std::setw(4);
        std::cout << (char) b << std::endl;
    }
    return 0;
}
