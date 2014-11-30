// old way of naming was <stdlib.h>; we get namespace of std too:
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

// stolen from: http://stackoverflow.com/questions/236129/split-a-string-in-c
template<typename T> std::vector<T> split(const T & str, const T & delimiters)
{
    std::vector<T> v;
    T::size_type start = 0;
    auto pos = str.find_first_of(delimiters, start);
    while (pos != T::npos) {
        if (pos != start) // ignore empty tokens
            v.emplace_back(str, start, pos - start);
        start = pos + 1;
        pos = str.find_first_of(delimiters, start);
    }

    if (start < str.length()) {
        // ignore trailing delimiter
        v.emplace_back(str, start, str.length() - start); // add what's left of the string
    }

    return v;
}

int main()
{
    const char* envPtr = std::getenv("path");
    if (nullptr == envPtr) {
        std::cerr << "failed to get path" << std::endl;
        return -1;
    }

    std::string envPath(envPtr);
    auto paths = split <std::string>(envPath, ";");
    for (auto path : paths) {
        std::cout << path << std::endl;
    }
}