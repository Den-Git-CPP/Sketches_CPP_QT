#include <iostream>
#include <string>
#include <regex>
#include <iterator>
using namespace std;

int main (int argc, const char** argv)
{
    string mystr = "This is software testing Help portal \n";
    cout << "Input string: " << mystr << endl;
    // регулярное выражение для соответствия строке, начинающейся с 'p'
    regex regexp ("p[a-zA-z]+");
    cout << "Replace the word 'portal' with word 'website' : ";
    // regex_replace() для замены совпадения со словом «веб-сайт»
    cout << regex_replace (mystr, regexp, "website");

    string result;
    cout << "Replace the word 'website' back to 'portal': ";
    // regex_replace() для замены совпадения на «portal»
    regex_replace (back_inserter (result), mystr.begin (), mystr.end (), regexp, "portal");
    cout << result;

    system ("pause");
    return 0;
};