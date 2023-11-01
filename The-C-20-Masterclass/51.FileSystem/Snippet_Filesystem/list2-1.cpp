#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <chrono>
/*
std::filesystem::path root{"G:\\ProjectC\\FileSystem"};

  // init list of all file paths in passed file tree:
  std::vector<std::filesystem::path> paths;
  try {
	std::filesystem::recursive_directory_iterator dirpos{root};
	std::copy(begin(dirpos), end(dirpos),
			  std::back_inserter(paths));
  }
  catch (const std::exception& e) {
	std::cerr << "EXCEPTION: " << e.what() << std::endl;
	return EXIT_FAILURE;
  }
*/
using time_point = std::chrono::system_clock::time_point;

std::string TimeGMTFormatToString(const time_point& in_time, const std::string& format) {
	std::time_t in_tt = std::chrono::system_clock::to_time_t(in_time);
	std::tm out_tm = *std::localtime(&in_tt);
	std::stringstream ss;
	ss << std::put_time(&out_tm, format.c_str());
	return ss.str();
}

int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");

	auto start = std::chrono::system_clock::now();
	std::string time_start = TimeGMTFormatToString(start, "%d.%m.%Y %H-%M");

	std::vector <std::filesystem::path> AllWorkDir {};
	auto basepath = std::filesystem::current_path() / "WorkDir.txt";
	
	std::ifstream fin(basepath);
	if (!fin.is_open()) {
		std::cout << "File could not be opened!" << '\n';
		return EXIT_FAILURE;
	}
	std::string line {};
	while (std::getline(fin, line)) {
		if (!line.empty()) {
			std::filesystem::path fpath(line);
			AllWorkDir.push_back(fpath);
		}
	}
	fin.close();

	std::vector<std::filesystem::path> all_paths;
	for (auto elem : AllWorkDir) {
		try {
			std::filesystem::recursive_directory_iterator dirpos {elem};
			std::copy(begin(dirpos), end(dirpos),
					  std::back_inserter(all_paths));
		}
		catch (const std::exception& e) {
			std::cerr << "EXCEPTION: " << e.what() << std::endl;
			return EXIT_FAILURE;
		}

	}
	int n {0};
	for(const std::filesystem::path &elem:all_paths)
	{
		std::string p = "E:\\ " + time_start;
		std::filesystem::path newpath {p/ elem.relative_path()};
		const auto copyOptions = std::filesystem::copy_options::recursive;
		if (is_directory(elem)) {
			
			++n;

			try {
				std::filesystem::create_directories(newpath);
			//	std::filesystem::copy(elem, newpath, copyOptions);
			//	std::cout << n << ".DIR parent_path() " << elem.string() << " to -> ";
			//	std::cout << "newpath " << newpath.string() << "\n";
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "EXCEPTION: " << e.what() << '\n';
				std::cerr << " path1: \"" << e.path1().string() << "\"\n";
			}
					
		}
		if (is_regular_file(elem)) {
			try {
			std::filesystem::copy(elem, newpath, copyOptions);
			//	std::cout << n << ".DIR parent_path() " << elem.string() << " to -> ";
			//	std::cout << "newpath " << newpath.string() << "\n";
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::cout << n << ".DIR parent_path() " << elem.string() << " to ->\n ";
				std::cout << "newpath " << newpath.string() << "\n";

				std::cerr << "EXCEPTION: " << e.what() << '\n';
				std::cerr << " path1: \"" << e.path1().string() << "\"\n";
			}
		}
	}


	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Time to copy:"<< diff.count() << " s\n";
	system("pause");
}