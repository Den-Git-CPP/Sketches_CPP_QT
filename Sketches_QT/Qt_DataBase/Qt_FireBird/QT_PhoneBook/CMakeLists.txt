cmake_minimum_required(VERSION 3.15)

project("_")
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("CMAKE_CURRENT_SOURCE_DIR =>PROJECT_NAME=> " ${PROJECT_NAME})

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Widgets
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
)

set(PROJECT_HEADERS
    include/qt_phonebook.h
)

set(PROJECT_SOURCES
       main.cpp
       source/qt_phonebook.cpp
       source/qt_phonebook.ui
)


set(PROJECT_RESOURCES
    .clang-format
)

add_executable(${PROJECT_NAME} WIN32
  ${PROJECT_HEADERS}
  ${PROJECT_SOURCES}
  ${PROJECT_RESOURCES}
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)
