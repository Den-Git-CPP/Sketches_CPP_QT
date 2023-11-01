#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <filesystem>
//#копирование файлов
//#параметры
//#$path1 = "D:\ОД\ИТОГИ"
//#$path1a = "D:\ОД\Дежурство ОД\"
//
//$path1 = "D:\ОД\"
//$path1b = "D:\Оповешение"
//
//$path2 = "D:\!Резервирование_Документов\"

using namespace std;
namespace fs = std::filesystem;
using namespace filesystem;

static tuple<path, file_status, size_t> file_info(const directory_entry& entry) {
    const auto fs(status(entry));
    return { entry.path(),
            fs,
            is_regular_file(fs) ? file_size(entry.path()) : 0u };

}

static char type_char(file_status fs) {
    if (is_directory(fs)) { return 'd'; }
    else if (is_symlink(fs)) { return 'l'; }
    else if (is_character_file(fs)) { return 'c'; }
    else if (is_block_file(fs)) { return 'b'; }
    else if (is_fifo(fs)) { return 'p'; }
    else if (is_socket(fs)) { return 's'; }
    else if (is_other(fs)) { return 'o'; }
    else if (is_regular_file(fs)) { return 'f'; }

    return '?';
}

static string rwx(perms p) {
    auto check([p](perms bit, char c) { return (p & bit) == perms::none ? '-' : c; });

    return { check(perms::owner_read,   'r'),
            check(perms::owner_write,  'w'),
            check(perms::owner_exec,   'x'),
            check(perms::group_read,   'r'),
            check(perms::group_write,  'w'),
            check(perms::group_exec,   'x'),
            check(perms::others_read,  'r'),
            check(perms::others_write, 'w'),
            check(perms::others_exec,  'x') };
}

static string size_string(size_t size) {
    stringstream ss;
    if (size >= 1000000000) { ss << (size / 1000000000) << 'G'; }
    else if (size >= 1000000) { ss << (size / 1000000) << 'M'; }
    else if (size >= 1000) { ss << (size / 1000) << 'K'; }
    else { ss << size << 'B'; }

    return ss.str();
}
//
//int main(int argc, char* argv[]) {
//	setlocale(LC_ALL, "Russian_Russia.1251");
//    //path dir{ argc > 1 ? argv[1] : "." };
//    auto basepath = std::filesystem::current_path();
//     auto filepath = basepath / "WorkDir.txt";
//    
//    std::vector<std::string>AllWorkDir{};
//
//    std::ifstream in(filepath);
//    if (!in.is_open()) {
//        std::cout << "File could not be opened!" << '\n';
//    }
//
//    auto line = std::string{};
//    while (std::getline(in, line)) {
//        if (!line.empty()) {
//
//            AllWorkDir.push_back(line);
//        }
//    }
//    in.close();
//
//    for (auto elem : AllWorkDir) {
//        if (!exists(elem)) {
//            cout << "Path " << elem << " does not exist.\n";
//            return 1;
//        }
//
//        vector<tuple<path, file_status, size_t>> items;
//
//        transform(directory_iterator{ elem }, {}, back_inserter(items), file_info);
//
//        for (const auto& [path, status, size] : items) {
//            cout << type_char(status) << rwx(status.permissions()) << "  "
//                << setw(4) << right << size_string(size) << "  "
//                << path.filename() << '\n';
//        }
//    }
//std:cin.get();
//	
//}

int main() {
	auto basepath = std::filesystem::current_path();
     auto filepath = basepath / "WorkDir.txt";
    
    std::vector<std::string>AllWorkDir{};

    std::ifstream in(filepath);
    if (!in.is_open()) {
        std::cout << "File could not be opened!" << '\n';
    }

    auto line = std::string{};
    while (std::getline(in, line)) {
        if (!line.empty()) {

            AllWorkDir.push_back(line);
        }
    }
    in.close();
	const auto copyOptions = fs::copy_options::update_existing
		| fs::copy_options::recursive
		//| fs::copy_options::directories_only
		;

	for (auto elem : AllWorkDir) {
		fs::path f_patch_temp(elem);
		fs::create_directories("_copy" / f_patch_temp.relative_path());
		fs::copy(elem, "_copy"/f_patch_temp.relative_path(), copyOptions);
	}
}