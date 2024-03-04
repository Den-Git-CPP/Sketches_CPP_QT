#include <iostream>
#include <fstream>
#include <optional>
#include <string>

std::optional<std::string> try_reading_file(const std::string& filename) {  // const, чтобы убедиться, что он не будет изменен
    std::ifstream file(filename);                                           // std::ifstream для чтения файлов
    if (!file.is_open()) {                                                  //если файл не открывается
        return std::nullopt;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); //Записал содержимое внутри файла
    return content;
}

int main() {
    const std::string filename = "exmpl.txt";
    
    
    auto fileContent = try_reading_file(filename);

    if (fileContent.has_value()) {
        std::cout << "File content:\n" << fileContent.value() << std::endl;
    } else {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
    }

    return 0;
}