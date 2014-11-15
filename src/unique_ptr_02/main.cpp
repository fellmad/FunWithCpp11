#include <windows.h>
#include <string>
#include <iostream>
#include <memory>

class Printer {
    std::string _printerName;
    HANDLE _printerHandle;
public:
    void print(const std::string jobName)
    {};
};

void leak_a_printer()
{
    Printer* pPrinter = new Printer {};
    pPrinter->print("leaky printer job");
}

void leak_a_printer_NOT()
{
    std::unique_ptr <Printer> printer {new Printer};
    printer->print("clean, fresh, unleaky print job");
}

int main()
{
    _CrtMemState startMemState {};
    _CrtMemCheckpoint(&startMemState);

    for (auto index = 0; index < 10; index++) {
        leak_a_printer();
        // leak_a_printer_NOT();
    }

    _CrtMemState currentMemState {};
    _CrtMemCheckpoint(&currentMemState);
    _CrtMemState result {};
    auto memDiff = _CrtMemDifference(&result, &startMemState, &currentMemState);

    if (memDiff > 0) {
        std::cerr << "OUCH. we've got about " <<
            result.lTotalCount << " bytes of leakage, dude." << std::endl;
        _CrtDumpMemoryLeaks();
    }
    else {
        std::cout << "no leaks dude" << std::endl;
    }

    return 0;
}