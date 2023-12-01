cmake_minimum_required(VERSION 3.21)

project(RegexNote)

file(GLOB SRC_FILES 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(src_file ${SRC_FILES})
    get_filename_component(target ${src_file} NAME_WLE)
    add_executable(${target} ${src_file})
    list(APPEND TARGETS ${target})
    message("target added: ${target}")
endforeach(src_file ${SRC_FILES})

foreach(target ${TARGETS})
    set_target_properties(${target}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )

endforeach(target ${TARGETS})