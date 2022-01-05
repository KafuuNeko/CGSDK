cmake_minimum_required(VERSION 3.9)
project(CGSDK_Project)

include_directories(src)

#设置使用C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#确保 Win32 环境下存在 WIN32 定义
if (WIN32)
    add_definitions(-DWIN32) 
endif ()

#必须是32位的
set(CMAKE_C_FLAGS "-m32 -fexec-charset=GBK")
set(CMAKE_CXX_FLAGS "-m32 -fexec-charset=GBK")


#Output
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#强制静态链接并取消输出函数@后缀
set(CMAKE_SHARED_LINKER_FLAGS "-static -Wl,--kill-at,--enable-stdcall-fixup")

include_directories(./src)

# ---------------------------------------------------------------------------------------
# THIRDPARTY
# ---------------------------------------------------------------------------------------
set(THIRDPARTY_DIR ./thirdparty)
include_directories(${THIRDPARTY_DIR})

# Library SQLite
file(GLOB_RECURSE THIRDPARTY_SQLITE_FILES ${THIRDPARTY_DIR}/sqlite/*.c)
add_library(sqlite STATIC ${THIRDPARTY_SQLITE_FILES})

# ---------------------------------------------------------------------------------------
# SDK
# ---------------------------------------------------------------------------------------
set(SRC_SDK_DIR ./src/sdk)
# file(GLOB_RECURSE SRC_SDK_FILES ${SRC_SDK_DIR}/*.cc)
# add_library(sdk STATIC ${SRC_SDK_FILES})


# ---------------------------------------------------------------------------------------
# Example
# ---------------------------------------------------------------------------------------
set(SRC_EXAMPLE_DIR ./src/example)
file(GLOB_RECURSE SRC_EXAMPLE_FILES ${SRC_EXAMPLE_DIR}/*.cc ${SRC_SDK_DIR}/*.cc)
add_library(example SHARED ${SRC_EXAMPLE_FILES})

set_target_properties(example PROPERTIES PREFIX "") # 去除 lib 前缀
set_target_properties(example PROPERTIES SUFFIX ".ext.dll") # 添加后缀

