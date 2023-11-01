#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <chrono>

//#копирование файлов
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
	}

	std::string line {};
	while (std::getline(fin, line)) {
		if (!line.empty()) {
			std::filesystem::path fpath(line);
			AllWorkDir.push_back(fpath);
		}
	}
	fin.close();

	for (auto elem : AllWorkDir) {
		const auto copyOptions = std::filesystem::copy_options::recursive;

		try {
			std::filesystem::path in {"D:\\!Резервирование_Документов\\Резервная копия" + time_start};
			in /= elem.relative_path();
			std::filesystem::create_directories(in);
		 	std::filesystem::copy(elem, in, copyOptions);
			std::cout << "Copy from:" <<elem<< " to "<<in<<".\n";
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "EXCEPTION: " << e.what() << '\n';
			std::cerr << " path1: \"" << e.path1().string() << "\"\n";
		}
		
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Time to copy:"<< diff.count() << " s\n";
	system("pause");
}