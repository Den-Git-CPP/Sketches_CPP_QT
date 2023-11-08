cmake_minimum_required(VERSION 3.5)

project("")
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message("CMAKE_CURRENT_SOURCE_DIR =>PROJECT_NAME=> " ${PROJECT_NAME})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Widgets
    Core
)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
    Core
)

set(PROJECT_SOURCES
    keyboardfilter.cpp
    keyboardfilter.h
    main.cpp
    widget.cpp
    widget.h
    widget.ui

)

add_executable(${PROJECT_NAME} WIN32
  ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
)


