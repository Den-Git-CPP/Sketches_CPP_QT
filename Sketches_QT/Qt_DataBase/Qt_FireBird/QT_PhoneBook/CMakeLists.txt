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
    Core
)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
    Core
)
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/icons_app.rc")

set(PROJECT_HEADERS
    include/model.h
    include/qt_phonebook.h
)

set(PROJECT_SOURCES
       main.cpp
       source/model.cpp
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
  ${APP_ICON_RESOURCE_WINDOWS}
 )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt6::Sql
)

SET (MY_RELEASE_DIR ${CMAKE_BINARY_DIR}_Deploy_${PROJECT_NAME})
message( "Create Directory:" ${MY_RELEASE_DIR})
file(MAKE_DIRECTORY ${MY_RELEASE_DIR})
message("CopyFile "  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe  " to "  ${MY_RELEASE_DIR} )
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe ${MY_RELEASE_DIR}
    COMMAND G:\\Qt\\6.5.3\\mingw_64\\bin\\windeployqt.exe ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer ${MY_RELEASE_DIR}
    COMMAND ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )

