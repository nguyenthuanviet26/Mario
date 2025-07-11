cmake_minimum_required(VERSION 3.16)

project(Mario)



# Set C++ standard

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Include directories for headers
include_directories(
 ${CMAKE_SOURCE_DIR}/inc
)


#Find all source file in /src folder
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)



# Path to Raylib 

set(RAYLIB_DIR "C:/raylib")


# Add Raylib

add_subdirectory(${RAYLIB_DIR} raylib_build)

# Create executable

add_executable(${PROJECT_NAME} ${SOURCES})

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})






# Link Raylib and required system libraries

target_link_libraries(Mario raylib)



if (WIN32)
target_link_libraries(Mario winmm gdi32 opengl32)

endif()

 