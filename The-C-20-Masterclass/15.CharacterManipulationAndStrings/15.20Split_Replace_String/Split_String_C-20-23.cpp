/*
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
std::vector<T>& split(const std::string& data_for_split, char delim, std::vector<T>& elems) {
	std::stringstream ss(data_for_split);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

int main()
{
	std::string str{ "The quick brown fox" };
	std::vector<std::string> v_str{};
	split<std::string>(str, ' ', v_str);
	std::string str1{ "12.25.35.400" };
	std::vector<int> v_int{};
	split<int>(str1, '.', v_int);
}

*/

/*
# include <iostream>
# include <ranges>
# include <string_view>
# include <vector>

using std::operator""sv;

int main() {
    std::string str = "hello world !";
    std::vector<std::string> result_v;
    auto splitted_string= std::ranges::views::split(str, " "sv);

    for(const auto& elem : splitted_string) {
        result_v.emplace_back(elem.data(), elem.size());
    }

    for(const auto& elem : result_v) {
        std::cout << elem << std::endl;
    }
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <print>
#include <ranges>
#include <boost/algorithm/string.hpp>

int main ()
{
    std::string text = "one two three four";
    std::vector<std::string> strs;
    boost::split (strs, text, boost::is_any_of (" "));
    for (const auto& item : strs) {
        std::cout << item << " ";
    }
    // OUTPUT: one two three four
    
    /*
    В С++20 появились рэнджи, вместе с std::views::split
    */
    auto range = text | std::views::split (' ');

    for (const auto& item : range) {
        std::cout << item << " ";
    }
    // OUTPUT: one two three four
    
    
    // С++23 с его std::ranges::to.
    // Если вам нужен вектор значений, чтобы по индексам получать доступ, можно сделать так:
    std::string text2 = "one two  three   four";
    auto strs         = text2 | std::views::split (' ') | std::views::filter ([] (auto&& sub_range) {
        return !sub_range.empty ();
    }) | std::ranges::to<std::vector<std::string>> ();
    std::print ("{}", strs);
    // OUTPUT: ["one", "two", "three", "four"]
    
    
    /*
    Если в исходной строке подряд идут несколько разделителей, то в результат попадают пустые строчки. Если вам так не нравится, то используйте std::views::filter:
    */
    std::string text3 = "one two  three   four";
    auto strs         = text3 | std::views::split (' ') | std::views::filter ([] (auto&& sub_range) {
        return !sub_range.empty ();
    }) | std::ranges::to<std::vector<std::string>> ();
    std::print ("{}", strs);
    // OUTPUT: ["one", "two", "three", "four"]
}
