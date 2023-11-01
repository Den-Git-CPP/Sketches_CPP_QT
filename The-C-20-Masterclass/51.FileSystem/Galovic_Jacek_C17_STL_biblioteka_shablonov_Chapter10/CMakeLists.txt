cmake_minimum_required(VERSION 3.10)

project(Galovic_Jacek_C17_STL_biblioteka_shablonov_Chapter10)

add_executable(canonical_filepath	canonical_filepath.cpp)
add_executable(dupe_compress		dupe_compress.cpp)
add_executable(file_size			file_size.cpp)
add_executable(file_type			file_type.cpp)
add_executable(grepper				grepper.cpp)
add_executable(list					list.cpp)
add_executable(normalizer			normalizer.cpp)
add_executable(renamer				renamer.cpp)


set_target_properties(
	canonical_filepath 
	dupe_compress 
	file_size 
	file_type 
	grepper 
	list 
	normalizer 
	renamer 
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)