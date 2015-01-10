#include <string>
#include <iostream>

void echo(std::string s) {
    std::cout << "result: " << s << std::endl;
}

int main() {
    // insert a raw string literal following this pattern:
    // R"delimiter(whatever chars you want here...)delimiter"
    // http://en.cppreference.com/w/cpp/language/string_literal

    std::string s = R"#(raw string literal with a hash '#' delimiter)#";
    echo(s);

    s = R"gobbledygook(a raw string literal with 'gobbledygook' as the delimiter)gobbledygook";
    echo(s);

    // delimiter can be empty:
    s = R"("dinosaur" developers use "\n" instead of std::endl.)";
    echo(s);

    s = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"; // error-prone...
    echo(s);

    s = R"(<?xml version="1.0" encoding="UTF-8"?>)"; // much, much nicer.
    echo(s);

    std::wcout << LR"(raw \t unicode string)" << std::endl;

    // microsoft apparently not yet up to date with C++11:
    //auto aUnicodeString = U"this is a unicode string";

    /*
    use this commented section to help insert a literal string that might get
    mangled by your syntax-sensitive text editor. there is an XML file in this folder...

    echo(s);
    */
}