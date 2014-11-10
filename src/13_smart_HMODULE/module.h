#include <string>
#include <memory>
#include <windows.h>

class module {
public:
    explicit module(std::wstring const& name)
        : handle {::LoadLibrary(name.c_str()), &::FreeLibrary}
    {}

    // other module related functions go here

private:

    using module_handle = std::unique_ptr < void, decltype(&::FreeLibrary) > ;

    module_handle handle;
};