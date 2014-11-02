#include <tchar.h>
#include <iostream>

auto _tmain(int /*argc*/, _TCHAR* /*argv*/[]) -> int
{
    std::wcout << L"hello from C++ 11 dude." << std::endl;
    return 0;
}
