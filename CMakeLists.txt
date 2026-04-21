cmake_minimum_required(VERSION 4.0)

project(embdGPIO C)

add_library(${CMAKE_PROJECT_NAME} INTERFACE)

target_include_directories(${CMAKE_PROJECT_NAME}
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC c_std_11)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
