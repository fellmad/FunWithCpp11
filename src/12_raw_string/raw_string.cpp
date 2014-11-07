#include <string>
#include <iostream>

void echo(std::string s) {std::cout << "the string is: " << std::endl << s << std::endl;}

int main() {
    // insert a raw string literal following this pattern:
    // R "delimiter( raw_character* )delimiter"    
    // http://en.cppreference.com/w/cpp/language/string_literal

    std::string s = R"#(raw string literal with a hash '#' delimiter)#";
    echo(s);

    s = R"gobbledygook(a raw string literal with 'gobbledygook' as the delimiter)gobbledygook";
    echo(s);

    // problem: this string          <?xml version="1.0" encoding="UTF-8"?>
    // needs to be escaped like this <?xml version=\"1.0\" encoding=\"UTF-8\"?>

    /*
    use this commented section to help insert a literal string that might get
    mangled by your syntax-sensitive text editor.
    there is an XML file in this folder...
    */

    s = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    echo(s);

    return 0;
}