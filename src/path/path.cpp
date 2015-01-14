////////////////////////////////////////////////////////////////////////////////
// http://en.cppreference.com/w/cpp/experimental/fs
////////////////////////////////////////////////////////////////////////////////

#include <filesystem>
#include <iostream>

namespace fs = std::tr2::sys;   // 2014: <filesystem> approved by ISO c++ committee

int main() {

    const fs::path currentFolder {"."};

    fs::directory_iterator directoryIterator(currentFolder);
    const fs::directory_iterator end;

    std::cout << "current folder: " << std::endl;
    for (; directoryIterator != end; ++directoryIterator) {
        std::cout << directoryIterator->path() << std::endl;
    }

    fs::path threeDir {"c:/windows/system32"};
    threeDir /= "spool";
    threeDir /= "drivers/x64";
    threeDir /= "3";

    directoryIterator = threeDir;

    std::cout << "3dir: " << std::endl;
    for (; directoryIterator != end; ++directoryIterator) {
        std::cout << directoryIterator->path() << std::endl;
    }
}

// use fs::wpath, fs::wdirectory_iterator, ... for unicode
// line 23: 'append operator' defined for path class.
// line 27: nice: assignment operator for path object to iterator object