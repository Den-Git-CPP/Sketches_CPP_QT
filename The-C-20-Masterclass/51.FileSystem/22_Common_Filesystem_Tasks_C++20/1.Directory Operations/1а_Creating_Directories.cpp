//Функция возвращает true, когда каталог был создан заново. Но она также может выдать исключение в случае ошибки. Вы можете использовать версию noexcept этой функции:
//bool create_directory( const std::filesystem::path& p, std::error_code& ec ) noexcept;
#include <filesystem>
#include <iostream>

int main() {
    std::filesystem::path dir = "/abc/cde"; // recursive?
    std::error_code ec{};
    if (std::filesystem::create_directory(dir, ec))
        std::cout << "Directory created successfully\n";
    else
    {
        std::cout << "Failed to create directory\n";
        std::cout << ec.message() << '\n';
    }
}
