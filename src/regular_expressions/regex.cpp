#include <iostream>
#include <regex>

int main()
{
    // std::regex pathSplitRegex("\\s*[;]+\\s*");   // old: ugly escapes: \\

    std::wregex pathSplitRegex(LR"(\s*[;]+\s*)");     // c++11 raw literal (FUN!)

    std::wstring path = LR"(c:\temp;d:\temp;c:\temp\123 abc;f:/a/b/c/d/j.txt;x:\y/z\w)";

    std::vector <std::wstring> folderNames;

    const std::wsregex_token_iterator end;

    for (
        std::wsregex_token_iterator iter(path.begin(), path.end(), pathSplitRegex, -1);
        iter != end;
        ++iter) {
        folderNames.push_back(*iter);
    }

    for (auto folderName : folderNames) {
        std::wcout << folderName << std::endl;
    }
}