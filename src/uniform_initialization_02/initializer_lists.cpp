// munged from: http://www.cplusplus.com/articles/EzywvCM9/

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// C++11: we don't need no stinkin' #TYPEDEF's
using AuthorLangMap = map < string, vector<pair<string, int>> > ;

int main()
{
    AuthorLangMap name_languages_year
    {
        {"Dennis Ritchie", {{"B", 1969}, {"C", 1973}}},
        {"Niklaus Wirth", {{"Pascal", 1970}, {"Modula-2", 1973}, {"Oberon", 1986}}},
        {"Bjarne Stroustrup", {{"C++", 1983}}},
        {"Walter Bright", {{"D", 1999}}}
    };

    // add a new entry to the map:
    name_languages_year["John McCarthy"] = {{"Lisp", 1958}};

    // add another - with empty vector:
    name_languages_year["Dwight Fellman"] = {};

    for (const auto& record : name_languages_year) {
        cout << record.first << endl;
        for (const auto& langs : record.second) {
            cout << "  " << langs.first << " " << langs.second << endl;
        }
    }
}