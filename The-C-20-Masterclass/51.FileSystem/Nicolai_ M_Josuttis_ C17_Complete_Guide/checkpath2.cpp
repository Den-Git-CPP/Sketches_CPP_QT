
#include <iostream>
#include <filesystem>
#include <cstdlib>    // for EXIT_FAILURE

int main(int argc, char* argv[]) {
	/*if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <path> \n";
		return EXIT_FAILURE;
	}*/

	std::filesystem::path p{ "G:\\ProjectC\\FileSystem" };
	if (is_regular_file(p)) {          // is path p a regular file?
		std::cout << '"' << p.string() << "\" exists with "
			<< file_size(p) << " bytes\n";
	}
	else if (is_directory(p)) {        // is path p a directory?
		std::cout << '"' << p.string() << "\" is a directory containing:\n";
		for (const auto& e : std::filesystem::directory_iterator{ p }) {
			std::cout << "  \"" << e.path().string() << "\"\n";
		}
	}
	else if (exists(p)) {              // does path p actually exist?
		std::cout << '"' << p.string() << "\" is a special file\n";
	}
	else {
		std::cout << "path \"" << p.string() << "\" does not exist\n";
	}
}

