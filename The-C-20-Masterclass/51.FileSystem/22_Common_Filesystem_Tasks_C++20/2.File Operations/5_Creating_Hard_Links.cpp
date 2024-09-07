//Жесткие ссылки предоставляют несколько записей каталога для одного файла. Используйте функцию create_hard_link для их создания.
#include <filesystem>
#include <iostream>
#include <fstream>
#include <format>

void ls() {
    for (const auto& entry : std::filesystem::directory_iterator(".")) 
        std::cout << std::format("{}, link count {}\n", entry.path().c_str(), entry.hard_link_count());
}

int main() {
    std::ofstream("target_file.txt") << "This is file 1";
    std::filesystem::path target = "target_file.txt";
    std::filesystem::path link = "hard_link_file.txt";
    try {
        std::filesystem::create_hard_link(target, link);
        std::cout << "Hard link created successfully\n";
        ls();
    } catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }
}
