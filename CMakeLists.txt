# CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(snake_station)

# 设置交叉编译
option(USE_CROSS_COMPILE "Use cross compile" ON)
if(USE_CROSS_COMPILE)
    # 设置交叉编译工具链
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    set(CMAKE_CXX_COMPILER /usr/local/arm/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi/bin/arm-linux-g++)
endif()

# 可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找当前目录下所有源文件，并保存到变量中
aux_source_directory(./src SNAKE_SRCS)

# 添加头文件搜索路径
include_directories(./inc)

# 指定生成目标
add_executable(snake_station ${SNAKE_SRCS})


