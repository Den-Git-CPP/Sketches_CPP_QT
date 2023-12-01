#include <algorithm>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main (int argc, const char** argv)
{
    const auto input = "please split,this,csv, ,line,\\,\n"s;
    const regex re{ "((?:[^\\\\,]|\\\\.)+)(?:,|$)" };
    const vector<string> m_vecFields{ 
        sregex_token_iterator (cbegin (input), cend (input), re, 1), sregex_token_iterator ()
        };
    cout << input << endl;
    copy (cbegin (m_vecFields), cend (m_vecFields), ostream_iterator<string> (cout, "\n"));

    return 0;
};