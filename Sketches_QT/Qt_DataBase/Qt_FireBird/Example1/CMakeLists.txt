cmake_minimum_required(VERSION 3.16)

project("_")
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("CMAKE_CURRENT_SOURCE_DIR =>PROJECT_NAME=> " ${PROJECT_NAME})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Core
    Sql
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 COMPONENTS Sql REQUIRED)

add_executable(${PROJECT_NAME}
  Example1.cpp
)
target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/DB
    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer
                    ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy
                    ${CMAKE_CURRENT_SOURCE_DIR}/test25.fdb
                    ${CMAKE_CURRENT_BINARY_DIR}/DB/test25.fdb
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )
