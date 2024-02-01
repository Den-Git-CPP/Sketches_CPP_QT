#include <iostream>
#include <iomanip>
#include <ranges>

int main() {
    const std::string text { "    Hello World" };
    std::cout << std::quoted(text) << '\n';

    auto conv = std::views::transform(
        std::views::drop_while(text, ::isspace), 
        ::toupper 
    );
    std::string temp(conv.begin(), conv.end());
    std::cout << std::quoted(temp) << '\n';

    auto conv2 = text|std::views::drop_while(::isspace)
                     |std::views::transform(::toupper)
                     |std::views::reverse;
    
    std::string temp1(conv2.begin(), conv2.end());
    std::cout << std::quoted(temp1) << '\n';

}