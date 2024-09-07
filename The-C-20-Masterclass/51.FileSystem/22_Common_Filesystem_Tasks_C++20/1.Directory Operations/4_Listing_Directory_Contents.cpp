#include <filesystem>
#include <iostream>
#include <exception>
#include <format>

void ls() {
    for (const auto& entry : std::filesystem::directory_iterator(".")) 
        std::cout << entry.path() << '\n';
}
void ls_req() {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(".")) 
        std::cout << entry.path() << '\n';
}

int main() {
    std::cout << "Listing Directory Contents\n";
    ls();
    std::cout << "\nListing Directory Contents Recursively\n";
    ls_req();
}
