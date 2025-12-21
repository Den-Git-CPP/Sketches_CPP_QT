cmake_minimum_required(VERSION 3.14)

project(QWorkWithBD LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

add_executable(QWorkWithBD
  main.cpp
  widget.h
  widget.cpp
  widget.ui
)
target_link_libraries(QWorkWithBD
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt6::Sql
)


#FILE SERVER (create a list)
set(PROJECT_NEED_DIR_EMB_SERVER
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/intl
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/plugins
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/sqldrivers
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/udf
)
set(PROJECT_NEED_FILE_EMB_SERVER
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/fbclient.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/ib_util.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/icudt30.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/icuin30.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/icuuc30.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/IDPLicense.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/IPLicense.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/Microsoft.VC80.CRT.manifest
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/msvcp80.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer/msvcr80.dll
)
#copy dir and file

foreach( file_dir ${PROJECT_NEED_DIR_EMB_SERVER})
    add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} ARGS -E copy
    ${file_dir}
    ${CMAKE_BINARY_DIR}
)
endforeach(file_dir)

foreach( file_fl ${PROJECT_NEED_FILE_EMB_SERVER})
   add_custom_command(
   TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} ARGS -E copy
    ${file_fl}
    ${CMAKE_BINARY_DIR}
)
endforeach(file_fl)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/DB

    #COMMAND ${CMAKE_COMMAND} -E copy_directory
    #                ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer
    #                ${CMAKE_BINARY_DIR}
    #
    # do the copying



    #Copy DB file
    COMMAND ${CMAKE_COMMAND} -E copy
                    ${CMAKE_CURRENT_SOURCE_DIR}/test25.fdb
                    ${CMAKE_CURRENT_BINARY_DIR}/DB/test25.fdb
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )
