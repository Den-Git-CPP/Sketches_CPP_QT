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
    include/add_dbf.h
)

set(PROJECT_SOURCES
       main.cpp
       source/model.cpp
       source/qt_phonebook.cpp
       source/qt_phonebook.ui
       source/add_dbf.cpp
       source/add_dbf.ui

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
    #COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/DB
    #Copy DB file
    COMMAND ${CMAKE_COMMAND} -E copy
                      ${CMAKE_CURRENT_SOURCE_DIR}/resources/test_rpr.fdb
                      ${CMAKE_CURRENT_BINARY_DIR}/DB/test_rpr.fdb
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )

#SET (MY_RELEASE_DIR ${CMAKE_BINARY_DIR}_Deploy_${PROJECT_NAME})
#message( "Create Directory:" ${MY_RELEASE_DIR})
#file(MAKE_DIRECTORY ${MY_RELEASE_DIR})
#message("CopyFile "  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe  " to "  ${MY_RELEASE_DIR} )
#add_custom_command(
#    TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe ${MY_RELEASE_DIR}
#    COMMAND G:\\Qt\\6.5.3\\mingw_64\\bin\\windeployqt.exe ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
#    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/EmbServer ${MY_RELEASE_DIR}
#    COMMAND ${MY_RELEASE_DIR}/${PROJECT_NAME}.exe
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#  )
#
