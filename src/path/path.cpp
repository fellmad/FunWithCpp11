////////////////////////////////////////////////////////////////////////////////
// http://en.cppreference.com/w/cpp/experimental/fs
// https://msdn.microsoft.com/en-us/library/dn986850.aspx
////////////////////////////////////////////////////////////////////////////////

#include <filesystem>
#include <iostream>

// nov 11 2016: either of these namespace decl's work:
// namespace fs = std::tr2::sys;   // 2014: <filesystem> approved by ISO c++ committee
namespace fs = std::experimental::filesystem::v1;

int main() {

    const fs::path currentFolder{ "." };
    fs::path::iterator pathIterator(currentFolder.begin());

    std::cout << "current folder: " << std::endl;
    for (; pathIterator != currentFolder.end(); ++pathIterator) {
        std::cout << *pathIterator << std::endl;
    }

    fs::path threeDir{ "c:/windows/system32" };
    threeDir /= "spool";
    threeDir /= "drivers/x64";
    threeDir /= "3";

    pathIterator = threeDir.begin();

    std::cout << "3dir: " << std::endl;
    for (; pathIterator != threeDir.end(); ++pathIterator) {
        std::cout << *pathIterator << std::endl;
    }
}
