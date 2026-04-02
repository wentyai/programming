cmake_minimum_required(VERSION 3.10)

project(EmployeeProject VERSION 1.0)

option(BUILD_SHARED_LIBS "Build shared library instead of static" OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if(BUILD_SHARED_LIBS)
    message(STATUS "Building SHARED library")
else()
    message(STATUS "Building STATIC library")
endif()

set(SOURCES src/employee.c)
set(HEADERS include/employee.h)

add_library(employee ${SOURCES})

target_include_directories(employee PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(program main.c)

target_link_libraries(program employee)

target_include_directories(program PRIVATE ${CMAKE_SOURCE_DIR}/include)