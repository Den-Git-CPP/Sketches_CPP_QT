//Библиотека std::filesystem предоставляет возможности для создания и управления временными каталогами  функция temp_directory_path()

#include <filesystem>
#include <iostream>
#include <fstream>

void create_temp_file(const std::filesystem::path& dir, const std::string& filename) {
    std::filesystem::path file_path = dir / filename;
    std::ofstream(file_path) << "This is a temporary file.";
    std::cout << "Temporary file created at: " << file_path << '\n';
}

int main() {
    std::filesystem::path temp_dir = std::filesystem::temp_directory_path() / "my_temp_directory";
    std::filesystem::create_directory(temp_dir);
    std::cout << "Temporary directory created at: " << temp_dir << '\n';

    create_temp_file(temp_dir, "temp_file.txt");

    std::cout << "Contents of the temporary directory:\n";
    for (const auto& entry : std::filesystem::directory_iterator(temp_dir)) {
        std::cout << entry.path() << '\n';
    }
}
/**
Temporary directory created at: "/tmp/my_temp_directory"
Temporary file created at: "/tmp/my_temp_directory/temp_file.txt"
Contents of the temporary directory:
"/tmp/my_temp_directory/temp_file.txt"
*/
