#include <iostream>
#include <string>
#include <atlstr.h>

// from some production code (NOT fun):
CComBSTR ULONG2String(ULONG value) {
    CComBSTR bstrStr;
    CString s;
    s.Format(TEXT("%d"), value);
    bstrStr.Empty();
    bstrStr.Append(s);
    return bstrStr;
}

// using std::to_string. FUN!
CComBSTR ULongToCComBSTR(const ULONG& value) {
    const auto& stringVal(std::to_string(value));
    const CComBSTR ccomBstrVal {stringVal.c_str()};
    return ccomBstrVal;
}

// more modern:
auto ULongToCComBSTR2(const ULONG& value) -> CComBSTR
{
    const auto& returnString = CComBSTR(std::to_wstring(value).c_str());
    return returnString;
}

int main() {

    auto s1 = ULONG2String(123);
    std::wcout << s1.m_str << std::endl;

    auto s2 = ULongToCComBSTR(456);
    std::wcout << s2.m_str << std::endl;

    auto s3(ULongToCComBSTR2(789));
    std::wcout << s3.m_str << std::endl;

    // more FUN: strings to numbers!
    const auto& num1 = std::stoi(" -123   ");
    const auto& num2 = std::stod("    456.78e-43 ");
    std::cout << "num1, num2: " << num1 << ", " << num2 << std::endl;
}

// 1) can we make a generic function - returning CString, CStringA /  W, 
//    CComBSTR, std::string, std::wstring?
//
// 2) ULongToCComBSTR2() returns a reference