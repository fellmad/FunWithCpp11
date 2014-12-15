////////////////////////////////////////////////////////////////////////////////
// http://en.cppreference.com/w/cpp/experimental/fs
////////////////////////////////////////////////////////////////////////////////

#include <filesystem>
#include <iostream>

namespace fs = std::tr2::sys;

int main()
{
    const fs::path currentFolder {"."};

    fs::directory_iterator directoryIterator(currentFolder);
    fs::directory_iterator end;

    std::cout << "current folder: " << std::endl;
    for (; directoryIterator != end; ++directoryIterator) {
        std::cout << directoryIterator->path() << std::endl;
    }

    fs::path threeDir {"c:/windows/system32"};
    threeDir /= "spool";
    threeDir /= "drivers/x64";
    threeDir /= "3";

    directoryIterator = threeDir;   // very nice

    std::cout << "3dir: " << std::endl;
    for (; directoryIterator != end; ++directoryIterator) {
        std::cout << directoryIterator->path() << std::endl;
    }
}