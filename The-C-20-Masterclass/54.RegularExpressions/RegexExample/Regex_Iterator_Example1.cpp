#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;
enum TOKENS {
    OPEN_PARENTHESIS,
    NEGATIVE_NUMBER,
    NON_NEGATIVE_NUMBER,
    CLOSE_PARENTHESIS,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EQUALITY,
    SIZE_TOKENS
};

int main (int argc, const char** argv)
{
    const auto input = "42/2 + -8\t=\n(2 + 2) * 2 * 2 -3"s;
    vector<TOKENS> tokens;
    const regex re{ "\\s*(\\(?)\\s*(-?\\s*\\d+)\\s*(\\)?)\\s*(?:(\\+)|(-)|(\\*)|(/)|(=))" };

    for_each (sregex_iterator (cbegin (input), cend (input), re), sregex_iterator (),
                             [&] (const auto& i) {
        if (i [1].length () > 0) {
            tokens.push_back (OPEN_PARENTHESIS);
        }

        tokens.push_back (i [2].str ().front () == '-' ? NEGATIVE_NUMBER : NON_NEGATIVE_NUMBER);

        if (i [3].length () > 0) {
            tokens.push_back (CLOSE_PARENTHESIS);
        }

        auto it = next (cbegin (i), 4);
        for (int result = ADDITION; it != cend (i); ++result, ++it) {
            if (it->length () > 0U) {
                tokens.push_back (static_cast<TOKENS> (result));
                break;
            }
        }
    });

    match_results<string::const_reverse_iterator> sm;

    if (regex_search (crbegin (input), crend (input), sm, regex{ tokens.back () == SUBTRACTION ? "^\\s*\\d+\\s*-\\s*(-?)" : "^\\s*\\d+\\s*(-?)" })) {
        tokens.push_back (sm [1].length () == 0 ? NON_NEGATIVE_NUMBER : NEGATIVE_NUMBER);
    }

    for (const auto& i : tokens) {
        switch (i) {
            case NEGATIVE_NUMBER:
                cout << "NEGATIVE_NUMBER\n";
                break;
            case NON_NEGATIVE_NUMBER:
                cout << "NON_NEGATIVE_NUMBER\n";
                break;
            case ADDITION:
                cout << "ADDITION\n";
                break;
            case SUBTRACTION:
                cout << "SUBTRACTION\n";
                break;
            case MULTIPLICATION:
                cout << "MULTIPLICATION\n";
                break;
            case DIVISION:
                cout << "DIVISION\n";
                break;
            case EQUALITY:
                cout << "EQUALITY\n";
                break;
            case OPEN_PARENTHESIS:
                cout << "OPEN_PARENTHESIS\n";
                break;
            case CLOSE_PARENTHESIS:
                cout << "CLOSE_PARENTHESIS\n";
        }
    }
    return 0;
};
//out:
//NON_NEGATIVE_NUMBER
//DIVISION
//NON_NEGATIVE_NUMBER
//ADDITION
//NEGATIVE_NUMBER
//EQUALITY
//OPEN_PARENTHESIS
//NON_NEGATIVE_NUMBER
//ADDITION
//NON_NEGATIVE_NUMBER
//CLOSE_PARENTHESIS
//MULTIPLICATION
//NON_NEGATIVE_NUMBER
//MULTIPLICATION
//NON_NEGATIVE_NUMBER
//SUBTRACTION
//NON_NEGATIVE_NUMBER