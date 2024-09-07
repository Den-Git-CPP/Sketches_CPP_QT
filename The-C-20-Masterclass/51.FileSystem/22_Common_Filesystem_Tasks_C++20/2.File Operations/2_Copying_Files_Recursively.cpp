//Копирование каталогов, включая их содержимое, можно выполнить с помощью функции копирования с рекурсивными параметрами.
#include <filesystem>
#include <iostream>
#include <fstream>

void create_temp_directories_and_files() {
    std::filesystem::create_directories("source_directory/subdir1");
    std::filesystem::create_directories("source_directory/subdir2");

    std::ofstream("source_directory/file1.txt") << "This is file 1";
    std::ofstream("source_directory/subdir1/file2.txt") << "This is file 2";
    std::ofstream("source_directory/subdir2/file3.txt") << "This is file 3";
}

int main() {
    create_temp_directories_and_files();

    std::filesystem::path src = "source_directory";
    std::filesystem::path dest = "destination_directory";
    try {
        std::filesystem::copy(src, dest, std::filesystem::copy_options::recursive);
        std::cout << "Directory copied successfully\n";
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(dest)) {
        std::cout << entry.path() << '\n';
    }
}
/**
Directory copied successfully
"destination_directory/subdir2"
"destination_directory/subdir2/file3.txt"
"destination_directory/subdir1"
"destination_directory/subdir1/file2.txt"
"destination_directory/file1.txt"
*/
