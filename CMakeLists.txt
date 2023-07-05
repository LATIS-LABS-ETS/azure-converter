cmake_minimum_required(VERSION 3.1)
project(AzureConverter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(k4a REQUIRED)
find_package(k4arecord REQUIRED)

#######CMAKE RELATED INCLUDE DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS} )

######ARGPARSE RELATED SETTINGS ##################
# Includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/argparse/argparse/include
    ${CMAKE_CURRENT_SOURCE_DIR}/argparse/modules/optional
    ${CMAKE_CURRENT_SOURCE_DIR}/argparse/modules/variant/include
)


# Flags
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra $ENV{STDLIB}")#STRICTER AND PREFERRED
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra $ENV{STDLIB}")#DURING DEVELOPMENT

# Shared library
add_library(argparse SHARED
    argparse/argparse/src/argparse.cpp
    argparse/argparse/src/option.cpp
    argparse/argparse/src/options.cpp
    argparse/argparse/src/parser.cpp
    argparse/argparse/src/variant.cpp
)
######END OF ARGPARSE RELATED SETTINGS ##################


# file(GLOB_RECURSE ARGPARSE_HEADERS argparse/include/*.h)
# file(GLOB_RECURSE ARGPARSE_CLASSES argparse/src/*.cpp)

file(GLOB_RECURSE HEADERS src/headers/*.h)
file(GLOB_RECURSE CLASSES src/classes/*.cpp)

add_executable(AzureConverter ${CLASSES} src/kinect.cpp)

target_include_directories(AzureConverter PUBLIC src/headers)

target_link_libraries(AzureConverter argparse)
target_link_libraries(AzureConverter k4a::k4a)
target_link_libraries(AzureConverter k4a::k4arecord)
target_link_libraries(AzureConverter ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} stdc++fs)#For filesystem utilities