cmake_minimum_required(VERSION 3.10)

project(My)

add_executable(list2	list2.cpp) 
add_executable(list2-1	list2-1.cpp) 
add_executable(file_system_copy_options		file_system_copy_options.cpp)
add_executable(filesystem_directory_iterator	filesystem_directory_iterator.cpp)
add_executable(filesystem_recursive_directory_iterator filesystem_recursive_directory_iterator.cpp)
#add_executable(filesystem_recursive_nonrecursive filesystem_recursive_nonrecursive.cpp)
add_executable(filesystem_system_copy_file filesystem_system_copy_file.cpp)
add_executable(filesystem_system_err filesystem_system_err.cpp)
add_executable(Last_Write_Time_File_to_String.cpp)


set_target_properties(
	list2
	list2-1
	file_system_copy_options
	filesystem_directory_iterator
	filesystem_recursive_directory_iterator
	#filesystem_recursive_nonrecursive
	filesystem_system_copy_file
	filesystem_system_err 
	Last_Write_Time_File_to_String
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

add_custom_command(
TARGET list2 list2-1 POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy
 ${CMAKE_SOURCE_DIR}/WorkDir.txt
 ${CMAKE_BINARY_DIR}/WorkDir.txt
 )