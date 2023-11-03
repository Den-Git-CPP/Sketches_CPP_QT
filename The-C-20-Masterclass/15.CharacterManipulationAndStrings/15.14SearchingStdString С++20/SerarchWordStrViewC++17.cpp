#include <format>
#include <iostream>
#include <string_view>

void find_word(std::string_view text, std::string_view word) {
    size_t pos = text.find(word);
    if (pos != std::string_view::npos)
        std::cout << std::format("Word found at position: {}\n", pos);
    else
        std::cout << "Word not found\n";
}

int main() {
    std::string str = "The quick brown fox jumps over the lazy dog";
    std::string_view sv = str;

    find_word(sv, "quick");
    find_word(sv, "lazy"); 
    find_word(sv, "hello"); 
}