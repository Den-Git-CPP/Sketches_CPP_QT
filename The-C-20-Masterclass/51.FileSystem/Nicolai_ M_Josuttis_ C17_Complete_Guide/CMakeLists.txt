cmake_minimum_required(VERSION 3.10)

project(Nicolai_M_Josuttis_C17_Complete_Guide)

add_executable(checkpath1 checkpath1.cpp)
add_executable(checkpath2 checkpath2.cpp)
add_executable(checkpath3 checkpath3.cpp)
add_executable(createfiles createfiles.cpp)
add_executable(dirsize dirsize.cpp)
add_executable(ftimeAsString_permAsString_Symlink ftimeAsString_permAsString_Symlink.cpp)

set_target_properties(
checkpath1 
checkpath2 
checkpath3 
createfiles 
dirsize 
ftimeAsString_permAsString_Symlink 

PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
