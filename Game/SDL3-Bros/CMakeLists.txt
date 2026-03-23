add_executable(SDL3-Bros
        main.cpp
        Source/testState.cpp
        Source/moveCommand.cpp
        Headers/MoveCommand.h
)

target_include_directories(SDL3-Bros PRIVATE Headers)
target_link_libraries(SDL3-Bros PRIVATE Engine SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf SDL3_mixer::SDL3_mixer)
