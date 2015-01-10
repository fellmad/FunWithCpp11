#include <string>
#include <iostream>
#include <memory>

// CRT leak articles:
// http://blogs.msdn.com/b/vcblog/archive/2011/10/11/10222603.aspx
// http://channel9.msdn.com/Series/C9-Lectures-Mahmoud-Saleh-Advanced-CRT/C9-Lectures-Mahmoud-Saleh-Advanced-CRT
// http://ecn.channel9.msdn.com/content/C9Lectures/CRT/CRT_Examples.zip
// https://code.msdn.microsoft.com/vstudio/CppResourceLeaks-ad3b7fdb

void leaker1() {
    char* buf = new char[1000] {'a', 'b', 'c'};
    buf[3] = 'd';
}

void nonleaker1() {
    std::unique_ptr <char> buf(new char[1000] {'a', 'b', 'c'});
    buf.get()[3] = 'd';
}

void nonleaker2() {
    auto buf = std::make_unique < char[] > (1000);
    buf[0] = 'a';
    buf[1] = 'b';
    buf[2] = 'c';
    buf[2] = 'd';
}

int main() {
    _CrtMemState startMemState {};
    _CrtMemCheckpoint(&startMemState);

    for (auto index = 0; index < 10; index++) {
        leaker1();
        //nonleaker1();
        //nonleaker2();
    }

    _CrtMemState currentMemState {};
    _CrtMemCheckpoint(&currentMemState);

    _CrtMemState result {};
    auto memDiff = _CrtMemDifference(&result, &startMemState, &currentMemState);
    if (memDiff > 0) {
        _CrtDumpMemoryLeaks();  // output to debug window
        std::cout << "OUCH. leaked " << result.lTotalCount << " bytes." << std::endl;
    }
    else {
        std::cout << "no leaks dude" << std::endl;
    }
}