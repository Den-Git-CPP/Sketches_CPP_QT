/**
*https://en.cppreference.com/w/cpp/regex/regex_match
*
 */
#include <cstddef>
#include <iostream>
#include <regex>
#include <string.h>

int main ()
{
    // Простое сопоставление с регулярным выражением
    const std::string fnames [] = { "foo.txt", "bar.txt", "baz.dat", "zoidberg" };
    const std::regex txt_regex ("[a-z]+\\.txt");

    for (const auto& fname : fnames)
        std::cout << fname << ": " << std::regex_match (fname, txt_regex) << '\n';

    // Извлечение частичного совпадения
    const std::regex base_regex ("([a-z]+)\\.txt");
    std::smatch base_match;

    for (const auto& fname : fnames)
        if (std::regex_match (fname, base_match, base_regex))
            // Первое sub_match — это вся строка; 
            // sub_match — первое выражение в скобках.
            if (base_match.size () == 2) {
                std::ssub_match base_sub_match = base_match [1];
                std::string base               = base_sub_match.str ();
                std::cout << fname << " has a base of " << base << '\n';
            }

    // Извлечение нескольких подсовпадений
    const std::regex pieces_regex ("([a-z]+)\\.([a-z]+)");
    std::smatch pieces_match;

    for (const auto& fname : fnames)
        if (std::regex_match (fname, pieces_match, pieces_regex)) {
            std::cout << fname << '\n';
            for (std::size_t i = 0; i < pieces_match.size (); ++i) {
                std::ssub_match sub_match = pieces_match [i];
                std::string piece         = sub_match.str ();
                std::cout << "  submatch " << i << ": " << piece << '\n';
            }
        }
}