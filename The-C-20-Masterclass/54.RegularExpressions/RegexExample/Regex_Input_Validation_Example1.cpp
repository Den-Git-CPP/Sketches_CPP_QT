#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main (int argc, const char** argv)
{
    string input;
    regex integer_expr ("(\\+|-)?[[:digit:]]+");
    // Если введенные данные верны, запросим другое число
    while (true) {
        cout << "Enter the input: ";
        cin >> input;
        if (!cin) {
            break;
        }
        // Выход, когда пользователь вводит q
        if (input == "q") {
            break;
        }
        if (regex_match (input, integer_expr)) {
            cout << "Input is an integer" << endl;
        }
        else {
            cout << "Invalid input : Not an integer" << endl;
        }
    }

    return 0;
};