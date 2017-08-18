cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME light_bulb)
project(${PROJECT_NAME})


#add_library( ../../../include/tinyfsm.hpp)
#target_include_directories(../../../include)

set(light_bulb_sources main.cpp)

add_executable(${PROJECT_NAME} ${light_bulb_sources})
#target_link_libraries(light_bulb)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)


