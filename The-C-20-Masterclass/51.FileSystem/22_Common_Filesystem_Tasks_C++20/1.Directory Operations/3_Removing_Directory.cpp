#include <filesystem>
#include <iostream>
#include <exception>

void ls() {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(".")) 
        std::cout << entry.path() << '\n';
}

int main() {
    std::filesystem::path dir = "test";
    try {
        if (std::filesystem::create_directory(dir))
            std::cout << "Directory created successfully\n";
        else
            std::cout << "Failed to create directory\n";

        ls();

        if (std::filesystem::remove(dir))
            std::cout << "Directory removed\n";
        else
            std::cout << "Failed to remove the directory...\n";

        ls();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }
}
