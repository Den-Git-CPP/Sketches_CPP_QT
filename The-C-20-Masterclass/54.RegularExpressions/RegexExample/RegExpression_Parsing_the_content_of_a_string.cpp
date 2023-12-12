#include <regex>
#include <string>
#include <iostream>
#include <cassert>

using namespace std::string_literals;
using namespace std;

bool is_valid (const std::string& regex_str, string_view str)
{
    const regex r (regex_str);
    return regex_match (str.data (), r);
}

int main (int argc, const char** argv)
{ //https://regexone.com/

    // Exercise 1: Matching Characters

    {
        assert (is_valid (R"(^\w+\.pdf$)", "document.pdf") == true);
        assert (is_valid (R"(\w+@\w+\.(?:com|in))", "vishalchovatiya@ymail.com") == true);
        assert (is_valid (R"(\w+@\w+\.(?:com|in))", "@abc.com") == false);
    }

    {
        const string input = "ABC:1->   PQR:2;;;   XYZ:3<<<"s;
        const regex rx (R"((\w+):(\w+);)");
        smatch m;
        
        assert (regex_match (input, m, rx) == false);
        assert (regex_search (input, m, rx) == true //
                && m.ready () == true               //
                && m [1] == "PQR"                  //
        );

         for (string &&str : m) {  
             cout << str << endl;
         }
    }

    /*

          {
              auto text{ "abc aa bca ca bbbb"s };
              auto rx      = std::regex{ R"(\b[a|b|c]{3}\b)"s };
              auto newtext = std::regex_replace (text, rx, "---"s);

              std::cout << newtext << '\n';
          }

          {
              auto text{ "abc aa bca ca bbbb"s };
              auto rx      = std::regex{ R"(\b[a|b|c]{3}\b)"s };
              auto newtext = std::regex_replace (text, rx, "---"s, std::regex_constants::format_first_only);

              std::cout << newtext << '\n';
          }

          {
              auto text{ "bancila, marius"s };
              auto rx      = std::regex{ R"((\w+),\s*(\w+))"s };
              auto newtext = std::regex_replace (text, rx, "$2 $1"s);

              std::cout << newtext << '\n';
          }

          {
              auto text{ "this is a example with a error"s };
              auto rx      = std::regex{ R"(\ba ((a|e|i|u|o)\w+))"s };
              auto newtext = std::regex_replace (text, rx, "an $1");

              std::cout << newtext << '\n';
          }

          {
              auto text{ "today is 1.06.2016!!"s };
              auto rx       = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))"s };
              auto newtext1 = std::regex_replace (text, rx, R"($5$4$3$2$1)");
              auto newtext2 = std::regex_replace (text, rx, R"([$`][$&][$'])");

              std::cout << newtext1 << '\n';
              std::cout << newtext2 << '\n';
          }
      */
    std::cout << "End\n";
    return 0;
};