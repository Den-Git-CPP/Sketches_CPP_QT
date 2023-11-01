#include <cstdlib>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
/*
Member constant 			Meaning
options controlling copy_file() when the file already exists
none 						Report an error (default behavior)
skip_existing 				Keep the existing file, without reporting an error.
overwrite_existing 			Replace the existing file
update_existing 			Replace the existing file only if it is older than the file being copied

options controlling  the effects of copy() on subdirectories
none 						Skip subdirectories (default behavior)
recursive 					Recursively copy subdirectories and their content

options controlling the effects of copy() on symbolic links
none 						Follow symlinks (default behavior)
copy_symlinks 				Copy symlinks as symlinks, not as the files they point to
skip_symlinks 				Ignore symlinks

options controlling the kind of copying copy() does
none 						Copy file content (default behavior)
directories_only 			Copy the directory structure, but do not copy any non-directory files
create_symlinks 			Instead of creating copies of files, create symlinks pointing to the originals. Note: the source path must be an absolute path unless the destination path is in the current directory.
create_hard_links 			Instead of creating copies of files, create hardlinks that resolve to the same files as the originals  
*/

int main()
{
    fs::create_directories("sandbox/dir/subdir");
    std::ofstream("sandbox/file1.txt").put('a');
    fs::copy("sandbox/file1.txt", "sandbox/file2.txt"); // copy file
    fs::copy("sandbox/dir", "sandbox/dir2"); // copy directory (non-recursive)
    const auto copyOptions = fs::copy_options::update_existing
                           | fs::copy_options::recursive
                           | fs::copy_options::directories_only
                           ;
    fs::copy("sandbox", "sandbox_copy", copyOptions); 
    static_cast<void>(std::system("tree"));
    fs::remove_all("sandbox");
    fs::remove_all("sandbox_copy");
}