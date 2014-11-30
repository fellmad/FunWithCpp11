#include <iostream>
#include <regex>

int main()
{
    // std::regex pathSplitRegex("\\s*[;]+\\s*");   // old: ugly escapes: \\

    std::regex pathSplitRegex(R"(\s*[;]+\s*)");     // c++11 raw literal

    std::string path = R"(c:\temp;d:\temp;c:\temp\123 abc;f:/a/b/c/d/j.txt;x:\y/z\w)";

    std::vector <std::string> folderNames;

    const std::sregex_token_iterator end;

    for (
        std::sregex_token_iterator iter(path.begin(), path.end(), pathSplitRegex, -1);
        iter != end;
        ++iter)
    {
        folderNames.push_back(*iter);
    }

    for (auto folderName : folderNames) {
        std::cout << folderName << std::endl;
    }
}
