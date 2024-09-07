#include <filesystem>
#include <iostream>
#include <fstream>

void display_file_content(const std::filesystem::path& path) {
    if (std::filesystem::exists(path)) {
        std::ifstream file(path);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::cout << "Content of " << path << ": " << content << '\n';
    } else {
        std::cout << path << " does not exist.\n";
    }
}

int main() {
    std::filesystem::path original_file = "original_file.txt";
    std::filesystem::path symlink = "symlink_to_file.txt";
    std::filesystem::path hardlink = "hardlink_to_file.txt";

    // Step 1: Create the original file
    std::ofstream(original_file) << "Hello World!";
    std::cout << "Original file created.\n";
    display_file_content(original_file);

    // Step 2: Create a symbolic link to the original file
    try {
        std::filesystem::create_symlink(original_file, symlink);
        std::cout << "Symbolic link created successfully.\n";
        display_file_content(symlink);
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }

    // Step 3: Create a hard link to the original file
    try {
        std::filesystem::create_hard_link(original_file, hardlink);
        std::cout << "Hard link created successfully.\n";
        display_file_content(hardlink);
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }

    // Step 4: Delete the original file and compare...
    std::filesystem::remove(original_file);
    std::cout << "Original file deleted.\n";
    display_file_content(symlink);
    display_file_content(hardlink);
}
