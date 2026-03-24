cmake_minimum_required(VERSION 3.16)
project(SDL3-Bros)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL-image EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL-mixer EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL-ttf EXCLUDE_FROM_ALL)
add_subdirectory(Game/SDL3-Bros)