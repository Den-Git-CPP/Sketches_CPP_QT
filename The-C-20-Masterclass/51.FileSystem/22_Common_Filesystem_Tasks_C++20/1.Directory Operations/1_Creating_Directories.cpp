#include <filesystem>
#include <iostream>
//Создание каталогов — это базовая, но важная операция create_directory.
int main() {
    std::filesystem::path dir = "example_directory";
    if (std::filesystem::create_directory(dir))
        std::cout << "Directory created successfully\n";
    else
        std::cout << "Failed to create directory\n";
}
