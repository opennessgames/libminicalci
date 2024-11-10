#
#    FileName : CMakeLists.txt
#    By : yzx
#    MakeTime : 2024-10-06 13:28:27
#    LastEditTime: 2024-11-10 21:52:28
#    Copyright (C) 2023-2024 openGames
#
cmake_minimum_required(VERSION 3.10)
project(libminicalci VERSION 1.0.0)

set(CMAKE_INSTALL_INCLUDEDIR "include")
set(CMAKE_INSTALL_SHARELIB "lib")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/debian/minicalci/lib")

file(GLOB_RECURSE SOURCES "src/*/*.c")
file(GLOB_RECURSE HEADERS "src/*/*.h")

add_library(minicalci SHARED ${SOURCES})

target_include_directories(minicalci PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(minicalci m)

install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/minicalci FILES_MATCHING PATTERN "*.h")

install(TARGETS minicalci
    EXPORT minicalciTargets
    LIBRARY DESTINATION /lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(NOT TARGET libminicalci_uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
        IMMEDIATE @ONLY
    )
    add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake")
endif()

