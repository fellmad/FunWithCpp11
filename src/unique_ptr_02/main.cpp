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

    static int _destructor_called_count;

    ~Printer()
    {
        _destructor_called_count++;
    }
};

int Printer::_destructor_called_count {};

void leak_a_printer()
{
    Printer* pPrinter = new Printer {};
    pPrinter->print("leaky printer job");
}

void leak_a_printer_array()
{
    Printer* printers = new Printer[10];
    delete printers; // see the bug?
}

void leak_a_printer_NOT()
{
    std::unique_ptr <Printer> printer {new Printer {}};
    printer->print("clean, fresh, unleaky print job");
}

void leak_a_printer_array_NOT()
{
    // You can use make_unique to create a unique_ptr to an array,
    // but you cannot use make_unique to initialize the array elements:
    auto printers = std::make_unique < Printer[] >(5);
    for (auto printer_index = 0; printer_index < 5; printer_index++) {
        printers[printer_index].print("printing");
    }
}

int main()
{
    _CrtMemState startMemState {};
    _CrtMemCheckpoint(&startMemState);

    for (auto index = 0; index < 10; index++) {
        // leak_a_printer();
        // leak_a_printer_array(); // will crash dbgcrt
        // leak_a_printer_NOT();
        leak_a_printer_array_NOT();
    }

    _CrtMemState currentMemState {};
    _CrtMemCheckpoint(&currentMemState);
    _CrtMemState result {};
    auto memDiff = _CrtMemDifference(&result, &startMemState, &currentMemState);

    if (memDiff > 0) {
        std::cerr << "OUCH. we've got about " << result.lTotalCount << " bytes of leakage, dude." << std::endl;
        std::cerr << "destructor called " << Printer::_destructor_called_count << " times. " << std::endl;
        _CrtDumpMemoryLeaks();
        return 0;
    }

    std::cout << "destructor called " << Printer::_destructor_called_count << " times. " << std::endl;

    std::cout << "no leaks dude" << std::endl;
#ifndef _DEBUG
    std::cerr << "try a DEBUG BUILD in vstudio." << std::endl;
#endif

    return 0;
    }