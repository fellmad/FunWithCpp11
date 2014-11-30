#include <windows.h>
#include <tchar.h>
#include <winspool.h>
#include <string>
#include <assert.h> // not C++ standard
#include <vector>
#include <iostream>
#include <algorithm>

#pragma comment(lib, "winspool.lib")  // MS pragmas: http://msdn.microsoft.com/en-us/library/d9x1s805.aspx

////////////////////////////////////////////////////////////////////////////////
// use win32 EnumPrinters() to return a list of printer names.
// level 2 / PRINTER_INFO_2 hardcoded.
////////////////////////////////////////////////////////////////////////////////
std::vector <std::wstring> GetPrinterNames()
{
    // 1) get size needed for printernames buffer:
    const DWORD flags = PRINTER_ENUM_LOCAL | PRINTER_ENUM_NETWORK | PRINTER_ENUM_CONNECTIONS;
    DWORD neededByteCount(0);
    DWORD returnedByteCount(0);
    const DWORD enumLevel(2);

    BOOL rc = ::EnumPrinters(
        flags,
        nullptr,	// use local server
        enumLevel,
        nullptr,	// no output buffer
        0,			// ask for zero bytes
        &neededByteCount,
        &returnedByteCount);

    assert(FALSE == rc);

    DWORD lastError = ::GetLastError();
    assert(ERROR_INSUFFICIENT_BUFFER == lastError);

    // 2) get the list of printernames.
    const DWORD printerInfo2BufferSize(neededByteCount);
    std::vector <byte> printerInfo2Bytes(printerInfo2BufferSize, 0);

    rc = ::EnumPrintersW(	// force UNICODE flavor regardless of build
        flags,
        nullptr,			// use local server
        enumLevel,
        &printerInfo2Bytes[0],
        printerInfo2BufferSize,
        &neededByteCount,
        &returnedByteCount);

    assert(rc);
    auto printerInfo2Ptr = reinterpret_cast <PPRINTER_INFO_2> (&printerInfo2Bytes[0]);

    std::vector <std::wstring> printerNames;

    for (DWORD printerIndex = 0; printerIndex < returnedByteCount; printerIndex++) {
        std::wstring printerName = printerInfo2Ptr[printerIndex].pPrinterName;
        printerNames.push_back(printerName);
    }

    return printerNames;
}

int main()
{
    const auto printerNames = GetPrinterNames();
    std::wcout << printerNames.size() << " printers installed:" << std::endl;
    for (auto printerName : printerNames) {
        std::wcout << " " << printerName << std::endl;
    }

    // fun: is "Microsoft XPS Document Writer" installed?
    const std::wstring msXpsDocWriterName {L"Microsoft XPS Document Writer"};
    auto result = std::find(printerNames.cbegin(), printerNames.cend(), msXpsDocWriterName);
    if (printerNames.cend() != result) {
        std::cout << std::endl;
        std::wcout << "found " << msXpsDocWriterName << std::endl;
    }

    return 0;
}
