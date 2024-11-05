cmake_minimum_required(VERSION 3.13.4)

project(CPPTEST VERSION 1.0)

configure_file(CPPTESTConfig.h.in CPPTESTConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(Adder)

# Ensure GLFW is built as a static library
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC Adder
    PUBLIC external/glfw/include
)

target_include_directories(${PROJECT_NAME}
    PRIVATE Adder
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} adder glfw)