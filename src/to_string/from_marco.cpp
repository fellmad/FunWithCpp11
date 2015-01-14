#include <iostream>
#include <string>
#include <atlstr.h>

// from some production code (NOT fun):
CComBSTR ULONG2String(ULONG value)
{
    CComBSTR bstrStr;
    CString s;
    s.Format(TEXT("%d"), value);
    bstrStr.Empty();
    bstrStr.Append(s);
    return bstrStr;
}

// using std::to_string. FUN!
CComBSTR ULongToCComBSTR(const ULONG &value)
{
    const auto &stringVal(std::to_string(value));
    const CComBSTR ccomBstrVal
    {
        stringVal.c_str()
    };
    return ccomBstrVal;
}

// more modern:
auto ULongToCComBSTR2(const ULONG &value) -> CComBSTR
{
    const auto &returnString = CComBSTR(std::to_wstring(value).c_str());
    return returnString;
}

// even more modern (at least more effective)
CComBSTR ULongToCComBSTR3(ULONG value) // comment: passing a ULONG as const & IMHO doesn't buy you anything... ULONG is not shorter than a pointer ... it's faster for Obejcts, which need copy, but not for simple data types, but it needs to be dereferrenced ...
{
    return  CComBSTR { std::to_wstring(value).c_str() };

    // BTW, according to the standard the below should work. Unfortunately, MS gives a compiler error... might have to do with the nature of CComBSTR...
    //  return{ std::to_wstring(value).c_str() };
}

int main()
{

    auto s1 = ULONG2String(123);
    std::wcout << s1.m_str << std::endl;

    auto s2 = ULongToCComBSTR(456);
    std::wcout << s2.m_str << std::endl;

    auto s3(ULongToCComBSTR2(789)); // you still call the copy constructor to create s3 from the stack !
    std::wcout << s3.m_str << std::endl;

    CComBSTR s4 { ULongToCComBSTR3(987) };  // do note the curly brackets --- don't call the copy constructor, just "move" the CComBSTR constructed in ULongToCComBSTR3 to s4 !
    std::wcout << s4.m_str << std::endl;

    // more FUN: strings to numbers!
    const auto &num1 = std::stoi(" -123   ");
    const auto &num2 = std::stod("    456.78e-43 ");
    std::cout << "num1, num2: " << num1 << ", " << num2 << std::endl;
}

// 1) can we make a generic function - returning CString, CStringA /  W,
//    CComBSTR, std::string, std::wstring?
//
// 2) ULongToCComBSTR2() returns a reference