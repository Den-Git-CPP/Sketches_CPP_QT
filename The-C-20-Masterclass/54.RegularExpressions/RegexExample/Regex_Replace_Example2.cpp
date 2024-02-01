#include <iostream>
#include <algorithm>
#include <regex>

int main ()
{
  std::string input{"line 1\n\n\nline 3\nline 4"};

  std::cout << "input:\n" << input << "\n";

  std::regex newlines_re("\n+");

  auto result = std::regex_replace(input, newlines_re, "");

  std::cout << "After:\n" << result << "\n";

  return 0;
}

/*
input:
line 1

line 3
line 4

After:
line 1line 3line 4
*/