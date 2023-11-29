#include <iostream>
#include <regex>
#include <string.h>

using namespace std;

int main (int argc, const char** argv)
{
    // строка для поиска
    string mystr = "She sells_sea shells in the sea shore";

    // регулярное выражение для шаблона, по которому нужно искать
    regex regexp ("s[a-z_]+");

    // тип флага для определения поведения сопоставления (в данном случае для строковых объектов)
    smatch m;

    // regex_search, который ищет регулярное выражение по шаблону в строке mystr
    regex_search (mystr, m, regexp);

    cout << "String that matches the pattern:" << endl;
    for (auto x : m) {
        cout << x << " ";
    }

    return 0;
};
