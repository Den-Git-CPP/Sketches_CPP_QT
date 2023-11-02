#include <iostream>
#include <ctime>
#include <chrono>
#pragma warning(disable : 4996) 
using namespace std;

int main() {
	// current date/time based on current system
	time_t now = time(0);
	cout << "Number of sec since January 1,1970 is:: " << now << endl;
	tm* ltm = localtime(&now);
	// print various components of tm structure.
	cout << "Year:" << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << 5 + ltm->tm_hour << ":";
	cout << 30 + ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
	auto start = std::chrono::system_clock::now()- std::chrono::seconds(7200);
	auto end = std::chrono::system_clock::now();
	std::string return_current_time_and_date()
	{
		auto now = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(now);
		std::stringstream ss;
		ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
		return ss.str();
	}
return 0;
}
