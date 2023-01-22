cmake_minimum_required(VERSION 3.15)

project("")
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("CMAKE_CURRENT_SOURCE_DIR =>PROJECT_NAME=> " ${PROJECT_NAME})

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Xml Core5Compat Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Xml Core5Compat Gui REQUIRED)


set(PROJECT_SOURCES
        xmlParser.cpp
        resource.qrc
       
)

add_executable(${PROJECT_NAME} WIN32
  ${PROJECT_SOURCES}
)
target_link_libraries(${PROJECT_NAME} 
PRIVATE 
Qt${QT_VERSION_MAJOR}::Core
Qt${QT_VERSION_MAJOR}::Widgets
Qt${QT_VERSION_MAJOR}::Xml
Qt${QT_VERSION_MAJOR}::Core5Compat
Qt${QT_VERSION_MAJOR}::Gui
)
