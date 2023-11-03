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