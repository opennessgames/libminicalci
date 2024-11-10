#
#    FileName : CMakeLists.txt
#    By : yzx
#    MakeTime : 2024-08-29 18:12:11
#    LastEditTime: 2024-10-06 02:45:18
#    Copyright (C) 2023-2024 openGames
#
cmake_minimum_required(VERSION 3.10)
project(libminicalci VERSION 1.0.0)

# 头文件和库的安装路径
set(CMAKE_INSTALL_INCLUDEDIR "include")
set(CMAKE_INSTALL_SHARELIB "lib")

# 库的输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/debian/minicalci/lib")

# 查找所有源文件和头文件
file(GLOB_RECURSE SOURCES "src/*/*.c")
file(GLOB_RECURSE HEADERS "src/*/*.h")

# 创建库
add_library(minicalci SHARED ${SOURCES})

# 将头文件目录添加到目标属性
target_include_directories(minicalci PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# 链接数学库
target_link_libraries(minicalci m)

# 安装头文件，保留目录结构
install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/minicalci FILES_MATCHING PATTERN "*.h")

# 安装库
install(TARGETS minicalci
    EXPORT minicalciTargets
    LIBRARY DESTINATION /lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 卸载
if(NOT TARGET libminicalci_uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
        IMMEDIATE @ONLY
    )
    add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake")
endif()

