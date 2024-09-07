//Если вам необходимо создать несколько вложенных каталогов, используйте функцию create_directories.

#include <filesystem>
#include <iostream>
#include <exception>

int main() {
    std::filesystem::path nested = "a/b/c";
    try {
        if (std::filesystem::create_directories(nested))
            std::cout << "Nested directories created successfully\n";
        else
            std::cout << "Failed to create nested directories\n";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }
}
