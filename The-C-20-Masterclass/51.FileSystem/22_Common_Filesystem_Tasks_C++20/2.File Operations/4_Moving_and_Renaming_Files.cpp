//Перемещение и переименование файлов или каталогов
#include <filesystem>
#include <iostream>
#include <fstream>

void ls() {
    for (const auto& entry : std::filesystem::directory_iterator(".")) 
        std::cout << entry.path() << '\n';
}

int main() {
    std::ofstream("old_file.txt") << "This is file 1";
    std::filesystem::path old_name = "old_file.txt";
    std::filesystem::path new_name = "new_file.txt";
    try {
        ls();
        std::filesystem::rename(old_name, new_name);
        std::cout << "File renamed/moved successfully\n";
        ls();
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }
}
