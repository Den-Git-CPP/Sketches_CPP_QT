#include <iostream>
#include <algorithm>

int main ()
{
  std::string input{"line 1\n\n\nline 3\nline 4"};
  std::cout << "input:\n" << input << "\n";
  input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
  std::cout << "After:\n" << input << "\n";
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