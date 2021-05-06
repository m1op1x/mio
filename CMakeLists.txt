###############################################################################
# Set project name.
###############################################################################
cmake_minimum_required(VERSION 3.9.0)
project(mio)

###############################################################################
# Set project variables.
###############################################################################
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

###############################################################################
# Find dependencies.
###############################################################################
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)

###############################################################################
# Create target library.
###############################################################################
file(GLOB_RECURSE PRJ_SRC ${SRC_DIR}/*.cpp)
add_library(${PROJECT_NAME} ${PRJ_SRC})

###############################################################################
# Set target include directories.
###############################################################################
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

###############################################################################
# Set target dependencies.
###############################################################################
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    SDL2::SDL2main
    SDL2::SDL2-static
    SDL2::SDL2_image
    SDL2::SDL2_ttf
    SDL2::SDL2_mixer)

###############################################################################
# Set target C++ standard.
###############################################################################
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

###############################################################################
# Set target warning flags.
###############################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif()
