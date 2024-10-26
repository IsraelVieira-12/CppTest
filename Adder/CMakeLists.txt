#cmake_minimum_required(VERSION 2.8)
#project(israelmath)
#add_library(israelmath adder.cpp)

add_library(adder adder.cpp adder.h)

#set_target_properties(israelmath PROPERTIES PUBLIC_HEADER "adder.h")
#install(TARGETS israelmath DESTINATION lib
#    PUBLIC_HEADER DESTINATION include
#    )