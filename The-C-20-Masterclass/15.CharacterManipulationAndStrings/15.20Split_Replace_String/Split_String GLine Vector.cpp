

#include <iostream>
#include <sstream>
#include <vector>



template <typename T>
std::vector<T>& split(const std::string& data_for_split, char delim, std::vector<T>& elems) {
	std::stringstream ss(data_for_split);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

int main()
{
	std::string str{ "The quick brown fox" };
	std::vector<std::string> v_str{};
	split<std::string>(str, ' ', v_str);
	std::string str1{ "12.25.35.400" };
	std::vector<int> v_int{};
	split<int>(str1, '.', v_int);


}
