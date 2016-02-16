// munged from: http://stackoverflow.com/questions/236129/split-a-string-in-c

#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

template <typename T>
std::vector <T> split(const T & str, const T & delimiters)
{
    std::vector<T> individual_items;
    T::size_type start = 0;
    auto pos = str.find_first_of(delimiters, start);
    while (pos != T::npos) {
        if (pos != start) // ignore empty tokens
            individual_items.emplace_back(str, start, pos - start);
        start = pos + 1;
        pos = str.find_first_of(delimiters, start);
    }

    if (start < str.length()) {
        // ignore trailing delimiter
        individual_items.emplace_back(str, start, str.length() - start); // add what's left of the string
    }
    return individual_items;
}

int main() {
    size_t requred_size {};
    getenv_s(&requred_size, nullptr, 0, "path");
    if (0 == requred_size) {
        std::cerr << "env var path not found" << std::endl;
        return -1;
    }

    std::unique_ptr <char> buf {new char[requred_size] {} };

    ::getenv_s(&requred_size, buf.get(), requred_size, "path");

    std::string envPath(buf.get());
    auto paths = split <std::string>(envPath, ";");
    for (auto path : paths) {
        std::cout << path << std::endl;
    }
}
