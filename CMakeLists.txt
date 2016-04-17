cmake_minimum_required(VERSION 3.5)

project(oml)

include_directories(include/agent include/common)

file(GLOB SOURCES "src/agent/*.cpp" "src/common/*.cpp")

add_executable(agent ${SOURCES})
