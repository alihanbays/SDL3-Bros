set(CMAKE_CXX_STANDARD 26)

add_executable(SDL3-Bros
        Source/TestState.cpp
        Source/Audio.cpp
        Source/ExitState.cpp
        Source/Globals.cpp
        Source/Texture.cpp
        Source/Util.cpp
        Source/GameActor.cpp
        main.cpp
)

target_include_directories(SDL3-Bros PRIVATE Headers)
target_link_libraries(SDL3-Bros PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf SDL3_mixer::SDL3_mixer)
