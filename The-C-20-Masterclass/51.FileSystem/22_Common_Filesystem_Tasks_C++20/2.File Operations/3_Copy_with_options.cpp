#include <filesystem>
#include <fstream>
#include <iostream>

/**
В каждой из следующих групп параметров может присутствовать не более одного параметра копирования, в противном случае поведение функций копирования не определено.

1.Параметры управления copy_file(), когда файл уже существует
none               Сообщить об ошибке (поведение по умолчанию).
skip_existing      Сохранить существующий файл, не сообщая об ошибке.
overwrite_existing Заменить существующий файл.
update_existing    Заменить существующий файл, только если он старше копируемого файла.

2.Параметры, управляющие эффектами copy() на подкаталоги
none               Пропускать подкаталоги (поведение по умолчанию).
recursive          Рекурсивно копировать подкаталоги и их содержимое.

3.Параметры, управляющие эффектами copy() на символических ссылках
none               Следовать символическим ссылкам (поведение по умолчанию).
copy_symlinks      Копировать символические ссылки как символические ссылки, а не как файлы, на которые они указывают.
skip_symlinks      Игнорировать символические ссылки.

4.Параметры, контролирующие тип копирования, который выполняет copy()
none               Копировать содержимое файла (поведение по умолчанию).
directories_only   Копировать структуру каталогов, но не копировать файлы, не являющиеся каталогами.
create_symlinks    Вместо создания копий файлов создавайте символические ссылки, указывающие на оригиналы. 
                   Примечание: исходный путь должен быть абсолютным, если только целевой путь не находится в текущем каталоге.
create_hard_links  Вместо создания копий файлов создавайте жесткие ссылки, которые разрешаются в те же файлы, что и оригиналы.
*/

void ls_req() {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(".")) 
        std::cout << entry.path() << '\n';
}

int main()
{
std::filesystem::create_directories("sandbox/dir/subdir");
std::ofstream("sandbox/file1.txt")<< "This is file 1";
std::filesystem::copy("sandbox/file1.txt", "sandbox/file2.txt");  // copy file
std::filesystem::copy("sandbox/dir", "sandbox/dir2");             // copy directory (non-recursive)
ls_req();
const auto copyOptions = std::filesystem::copy_options::update_existing
                        | std::filesystem::copy_options::recursive
                        | std::filesystem::copy_options::directories_only;
                        
std::filesystem::copy("sandbox", "sandbox_copy", copyOptions); 

std::cout<<"============\n";
ls_req();

static_cast<void>(std::system("tree"));
std::filesystem::remove_all("sandbox");
std::filesystem::remove_all("sandbox_copy");
}
