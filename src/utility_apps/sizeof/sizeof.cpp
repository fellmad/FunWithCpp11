///////////////////////////////////////////////////////////////////////////////
// sizeof different data types
///////////////////////////////////////////////////////////////////////////////
#include <afx.h>
#include <iomanip>
#include <wtypes.h>
#include <wctype.h>
#include <wingdi.h>
#include <oaidl.h>
#include <sqltypes.h>
#include <iostream>
#include <string>
#include <comdef.h>
#include <vptype.h>

#define dumpsize(typ) \
{\
   std::cout << std::setiosflags(std::ios::left); \
   std::cout.width(32); \
   std::cout << #typ << sizeof(typ) << std::endl; \
}

int main()
{
#ifdef _WIN64
    std::cout << "sizeof C++ data types (64-bit):" << std::endl << std::endl;
#else
    std::cout << "sizeof C++ data types (32-bit):" << std::endl << std::endl;
#endif

    dumpsize(ACL);
    dumpsize(AMVPDATAINFO);
    dumpsize(AMVPDIMINFO);
    dumpsize(AMVPSIZE);
    dumpsize(BLOB);
    dumpsize(bool);
    dumpsize(BOOL);
    dumpsize(_bstr_t);
    dumpsize(BSTR);
    dumpsize(BSTRBLOB);
    dumpsize(BYTE);
    dumpsize(BYTE_BLOB);
    dumpsize(BYTE_SIZEDARR);
    dumpsize(signed char);
    dumpsize(CLIPDATA);
    dumpsize(COAUTHIDENTITY);
    dumpsize(COAUTHINFO);
    dumpsize(COLORREF);
    dumpsize(CSPLATFORM);
    dumpsize(CString);
    dumpsize(CStringArray);
    dumpsize(CStringList);
    dumpsize(CY);
    dumpsize(DATE_STRUCT);
    dumpsize(double);
    dumpsize(DWORD);
    dumpsize(DWORD_BLOB);
    dumpsize(DWORD_PTR);
    dumpsize(FILETIME);
    dumpsize(FLAGGED_BYTE_BLOB);
    dumpsize(FLAGGED_WORD_BLOB);
    dumpsize(float);
    dumpsize(FLOAT);
    dumpsize(GDI_NONREMOTE);
    dumpsize(GUID);
    dumpsize(HANDLE);
    dumpsize(HDBC);
    dumpsize(HDESK);
    dumpsize(HGDIOBJ);
    dumpsize(HINSTANCE);
    dumpsize(HKEY);
    dumpsize(HKL);
    dumpsize(HMODULE);
    dumpsize(HPEN);
    dumpsize(HRGN);
    dumpsize(HRSRC);
    dumpsize(HSTMT);
    dumpsize(HSTR);
    dumpsize(HTASK);
    dumpsize(HWINSTA);
    dumpsize(HYPER_SIZEDARR);
    dumpsize(int);
    dumpsize(LARGE_INTEGER);
    dumpsize(LOGBRUSH);
    dumpsize(LOGPALETTE);
    dumpsize(_LONG_SIZEDARR);
    dumpsize(signed long);
    dumpsize(long double);
    dumpsize(long int);
    dumpsize(long long);            // c++11
    dumpsize(unsigned long long);   // c++11
    dumpsize(long);
    dumpsize(LONG_PTR);
    dumpsize(LPBYTE);
    dumpsize(LPCVOID);
    dumpsize(LPINT);
    dumpsize(LPLONG);
    dumpsize(LPVOID);
    dumpsize(LPWORD);
    dumpsize(LPDWORD);
    dumpsize(MSG);
    dumpsize(OBJECTID);
    dumpsize(ODBCINT64);
    dumpsize(OLECHAR);
    dumpsize(PALETTEENTRY);
    dumpsize(PBYTE);
    dumpsize(PBOOL);
    dumpsize(PFLOAT);
    dumpsize(PINT);
    dumpsize(POINT);
    dumpsize(PDWORD);
    dumpsize(PWORD);
    dumpsize(POINTL);
    dumpsize(PROPID);
    dumpsize(PTR);
    dumpsize(PVOID);
    dumpsize(QUERYCONTEXT);
    dumpsize(RECT);
    dumpsize(RECTL);
    dumpsize(RemHBITMAP);
    dumpsize(RemHBRUSH);
    dumpsize(RemHENHMETAFILE);
    dumpsize(RemHGLOBAL);
    dumpsize(RemHMETAFILEPICT);
    dumpsize(RemHPALETTE);
    dumpsize(RemotableHandle);
    dumpsize(remoteMETAFILEPICT);
    dumpsize(RETCODE);
    dumpsize(SCHAR);
    dumpsize(SCODE);
    dumpsize(SECURITY_ATTRIBUTES);
    dumpsize(SECURITY_DESCRIPTOR);
    dumpsize(_SHORT_SIZEDARR);
    dumpsize(short int);
    dumpsize(SHORT);
    dumpsize(short);
    dumpsize(SID);
    dumpsize(SID_IDENTIFIER_AUTHORITY);
    dumpsize(signed short);
    dumpsize(SIZE);
    dumpsize(SIZEL);
    dumpsize(SLONG);
    dumpsize(SQLCHAR);
    dumpsize(SQLDATE);
    dumpsize(SQLDECIMAL);
    dumpsize(SQLGUID);
    dumpsize(SQLHANDLE);
    dumpsize(SQLHDBC);
    dumpsize(SQLHDESC);
    dumpsize(SQLHENV);
    dumpsize(SQLHSTMT);
    dumpsize(SQLHWND);
    dumpsize(SQLNUMERIC);
    dumpsize(SQLPOINTER);
    dumpsize(SQLRETURN);
    dumpsize(SQLSCHAR);
    dumpsize(SQLSMALLINT);
    dumpsize(SQLTCHAR);
    dumpsize(SQLTIME);
    dumpsize(SQLTIMESTAMP);
    dumpsize(SQLUBIGINT);
    dumpsize(SQLUINTEGER);
    dumpsize(SQLUINTEGER);
    dumpsize(SQLUSMALLINT);
    dumpsize(SQLVARCHAR);
    dumpsize(SQLWCHAR);
    dumpsize(SQL_DAY_SECOND_STRUCT);
    dumpsize(SQL_INTERVAL_STRUCT);
    dumpsize(SQL_NUMERIC_STRUCT);
    dumpsize(SQL_TIMESTAMP_STRUCT);
    dumpsize(SQL_TIME_STRUCT);
    dumpsize(SQL_YEAR_MONTH_STRUCT);
    dumpsize(SSHORT);
    dumpsize(std::string);
    dumpsize(SWORD);
    dumpsize(SYSTEMTIME);
    dumpsize(tagDEC);
    dumpsize(TCHAR);
    dumpsize(TEXTMETRICW);
    dumpsize(TIMESTAMP_STRUCT);
    dumpsize(TIME_STRUCT);
    dumpsize(type_info);
    dumpsize(UCHAR);
    dumpsize(UINT);
    dumpsize(UINT_PTR);
    dumpsize(ULARGE_INTEGER);
    dumpsize(ULONG);
    dumpsize(ULONGLONG);
    dumpsize(userBITMAP);
    dumpsize(userCLIPFORMAT);
    dumpsize(userHBITMAP);
    dumpsize(userHENHMETAFILE);
    dumpsize(userHGLOBAL);
    dumpsize(userHMETAFILE);
    dumpsize(userHMETAFILEPICT);
    dumpsize(userHPALETTE);
    dumpsize(USHORT);
    dumpsize(UWORD);
    dumpsize(_variant_t);
    dumpsize(VARIANT);
    dumpsize(VARIANT_BOOL);
    dumpsize(VARTYPE);
    dumpsize(VT_ARRAY);
    dumpsize(VT_BLOB);
    dumpsize(VT_BLOB_OBJECT);
    dumpsize(VT_BOOL);
    dumpsize(VT_BSTR);
    dumpsize(VT_BYREF);
    dumpsize(VT_CARRAY);
    dumpsize(VT_CF);
    dumpsize(VT_CLSID);
    dumpsize(VT_CY);
    dumpsize(VT_DATE);
    dumpsize(VT_DECIMAL);
    dumpsize(VT_DISPATCH);
    dumpsize(VT_EMPTY);
    dumpsize(VT_ERROR);
    dumpsize(VT_FILETIME);
    dumpsize(VT_HRESULT);
    dumpsize(VT_I1);
    dumpsize(VT_I2);
    dumpsize(VT_I4);
    dumpsize(VT_INT);
    dumpsize(VT_LPSTR);
    dumpsize(VT_LPWSTR);
    dumpsize(VT_NULL);
    dumpsize(VT_PTR);
    dumpsize(VT_R4);
    dumpsize(VT_R8);
    dumpsize(VT_RECORD);
    dumpsize(VT_RESERVED);
    dumpsize(VT_SAFEARRAY);
    dumpsize(VT_STORAGE);
    dumpsize(VT_STORED_OBJECT);
    dumpsize(VT_STREAM);
    dumpsize(VT_STREAMED_OBJECT);
    dumpsize(VT_UI1);
    dumpsize(VT_UI2);
    dumpsize(VT_UI4);
    dumpsize(VT_UINT);
    dumpsize(VT_UNKNOWN);
    dumpsize(VT_USERDEFINED);
    dumpsize(VT_VARIANT);
    dumpsize(VT_VECTOR);
    dumpsize(VT_VOID);
    dumpsize(WCHAR);
    dumpsize(wchar_t);
    dumpsize(wctrans_t);
    dumpsize(wctype_t);
    dumpsize(wint_t);
    dumpsize(WORD);
    dumpsize(WORD_BLOB);
    dumpsize(WPARAM);
    dumpsize(std::wstring);

    return 0;
}