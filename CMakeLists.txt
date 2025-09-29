cmake_minimum_required(VERSION 3.28)

project(interview_questions
    VERSION 0.1
    LANGUAGES CXX
    DESCRIPTION "Solutions to common interview questions"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE MODULES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm
)

add_executable(my_app ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_sources(my_app PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES ${MODULES})
target_compile_options(my_app PRIVATE -fmodules -Wall -Wextra -Wpedantic)
