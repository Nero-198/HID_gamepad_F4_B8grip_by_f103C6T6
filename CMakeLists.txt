cmake_minimum_required(VERSION 3.20)

project("F-4_B8_Controller_by_f103C6T6" C CXX ASM)

include(cmake/st-project.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties(${PROJECT_NAME})