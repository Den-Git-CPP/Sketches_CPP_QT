#include <filesystem>
#include <fstream>     
#include <iostream>
void create_temp_directories_and_files() {
    std::filesystem::create_directories("source_directory/subdir1");
    std::filesystem::create_directories("source_directory/subdir2");
    std::ofstream("source_directory/file1.txt") << "This is file 1";
    std::ofstream("source_directory/subdir1/file2.txt") << "This is file 2";
    std::ofstream("source_directory/subdir2/file3.txt") << "This is file 3";
}
int main() {

    create_temp_directories_and_files();
    
    std::filesystem::path src = "source_directory/file1.txt";
    std::filesystem::path dest = "source_directory/subdir1/file1.txt";
    try {
        std::filesystem::copy(src, dest);
        std::cout << "File copied successfully\n"; 
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }
}
//File copied successfully
