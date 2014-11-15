#include <string>
#include <iostream>
#include <memory>
#include <numeric>

// http://blogs.msdn.com/b/vcblog/archive/2011/10/11/10222603.aspx
// http://channel9.msdn.com/Series/C9-Lectures-Mahmoud-Saleh-Advanced-CRT/C9-Lectures-Mahmoud-Saleh-Advanced-CRT
// http://ecn.channel9.msdn.com/content/C9Lectures/CRT/CRT_Examples.zip
// todo: https://code.msdn.microsoft.com/vstudio/CppResourceLeaks-ad3b7fdb

void leaker1()
{
    char* buf = new char[100];
    buf[123] = 'c';
}

void leaker2()
{
    char* buf = new char[2000];
    delete buf;  // 2nd most common c++ bug
}

void nonleaker()
{
    std::unique_ptr <char> buf(new char[1000] {});

    buf.get()[0] = 'x';
    buf.get()[1] = 'y';
}

int main()
{
    _CrtMemState startMemState {};
    _CrtMemCheckpoint(&startMemState);

#if 0
    for (auto index = 0; index < 10; index++) {
        leaker1();
    }
#endif

    _CrtMemState currentMemState {};
    _CrtMemCheckpoint(&currentMemState);
    int memDiff {};

#if 0
    _CrtMemState result;
    auto memDiff = _CrtMemDifference(&result, &startMemState, &currentMemState);
    if (memDiff > 0) {
        _CrtDumpMemoryLeaks();
    }
#endif

#if 0
    _CrtMemCheckpoint(&startMemState);
    leaker2();
    _CrtMemCheckpoint(&currentMemState);
    if (memDiff > 0) {
        _CrtDumpMemoryLeaks();
    }
#endif

    _CrtMemCheckpoint(&startMemState);

    for (auto index = 0; index < 10000; index++) {
        nonleaker();
    }

    _CrtMemCheckpoint(&currentMemState);
    if (memDiff > 0) {
        _CrtDumpMemoryLeaks();
    }
    else {
        std::cout << "no leaks dude" << std::endl;
    }

    _CrtMemCheckpoint(&startMemState);

    return 0;
}