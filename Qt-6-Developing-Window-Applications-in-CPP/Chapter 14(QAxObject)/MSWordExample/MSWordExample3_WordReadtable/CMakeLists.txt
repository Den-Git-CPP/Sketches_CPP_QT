cmake_minimum_required(VERSION 3.28)

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
    Gui
    AxContainer
)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
    Core
    Gui
    AxContainer
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
   )

add_executable(${PROJECT_NAME} WIN32
  ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::AxContainer
)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/resource
#        ${CMAKE_BINARY_DIR}/resource
#)
#SET (MY_RELEASE_DIR ${CMAKE_BINARY_DIR}_Deploy_${PROJECT_NAME}) POST_BUILD
##SET (MY_RELEASE_DIR ${CMAKE_CURRENT_LIST_DIR}_MyReleaseDir_EXE)
#message( "Create Directory:" ${MY_RELEASE_DIR})
#file(MAKE_DIRECTORY ${MY_RELEASE_DIR})
#message("CopyFile "  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe  " to "  ${MY_RELEASE_DIR} )
#
#add_custom_command(
#    TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe ${MY_RELEASE_DIR}
#    COMMAND G:\\Qt\\6.5.3\\mingw_64\\bin\\windeployqt6.exe ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
#    #COMMAND ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#  )

