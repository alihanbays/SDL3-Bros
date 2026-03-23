add_library(Engine STATIC
        Source/sprite.cpp
        Source/texture.cpp
        Source/globals.cpp
        Source/audio.cpp
        Source/exitState.cpp
        Source/util.cpp
        Headers/command.h
)

target_include_directories(Engine PUBLIC Headers)
target_link_libraries(Engine PUBLIC SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf SDL3_mixer::SDL3_mixer)
