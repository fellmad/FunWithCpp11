////////////////////////////////////////////////////////////////////////////////
// http://en.cppreference.com/w/cpp/experimental/fs
// https://msdn.microsoft.com/en-us/library/dn986850.aspx
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <filesystem>   // need c++ 2017 or later

namespace fs = std::filesystem;

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
