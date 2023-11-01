#pragma warning(disable : 4996) 
#include <windows.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <filesystem>
#include <ctime>

//cmd_file = "C://Program\" \"Files/7-Zip/7z.exe\" ";// a -ssw -tzip -mx5 -r0 D://1/1.rar D://123

namespace fs = std::filesystem;

void HideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_MINIMIZE);//SW_MINIMIZE or SW_HIDE
}
void ShowConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}
bool IsConsoleVisible() {
	return (::IsWindowVisible(::GetConsoleWindow()) != FALSE);
}

using time_point = std::chrono::system_clock::time_point;

std::string TimeGMTFormatToString(const time_point& in_time, const std::string& format) {
	std::time_t in_tt = std::chrono::system_clock::to_time_t(in_time);
	std::tm out_tm = *std::localtime(&in_tt);
	std::stringstream ss;
	ss << std::put_time(&out_tm, format.c_str());
	return ss.str();
}

template <typename TP>
std::time_t to_time_t(TP tp) {
	using namespace std::chrono;
	auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
	return system_clock::to_time_t(sctp);
}

void remove_files_older_than(fs::path const& path, std::chrono::time_point<std::chrono::system_clock> start_time, int seconds) 
{
	try{
		if (fs::exists(path)) {
			for (auto const& entry : fs::directory_iterator(path)) {
				std::filesystem::file_time_type file_time = std::filesystem::last_write_time(entry);
				std::time_t tt = to_time_t(file_time);
								
				std::time_t st = std::chrono::system_clock::to_time_t(start_time);

				if (seconds < difftime(st, tt)){
					fs::remove(entry.path());
				}
			}
		}

	}
	catch (std::exception const& ex) {
		std::cerr << ex.what() << "\n";
	}

}
int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	HideConsole();

	auto start = std::chrono::system_clock::now();
	std::string time_start = TimeGMTFormatToString(start, "%d.%m.%Y_%H-%M");
	std::string p_to_archive {"D:\\Резервная_копия_"};
	p_to_archive.append(time_start);
	p_to_archive.append(".rar");

	std::vector<std::string> vector_all_commands {
		"7z a -ssw -tzip -mx5 -r0 " + p_to_archive + " D://backup_log_" + time_start + ".txt",
		"7z a -ssw -tzip -mx5 -r0 " + p_to_archive + " D://backup_log_" + time_start + ".txt",
		"7z a -ssw -tzip -mx5 -r0 " + p_to_archive + " D://backup_log_" + time_start + ".txt",
		"del D:\\backup_log_" + time_start + ".txt"
	};

	for (auto cmd_file : vector_all_commands) {
		system(cmd_file.c_str());
	};
	
	std::filesystem::copy(p_to_archive, "S:\\!Резервирование_Документов");

	auto path1 = R"(D:\\!Резервирование_Документов\)";
	auto path2 = R"(S:\\!Резервирование_Документов\)";

	remove_files_older_than(path1, start, 691200); //8 суток в секундах  691200
	remove_files_older_than(path2, start, 691200); //8 суток в секундах  691200

}
