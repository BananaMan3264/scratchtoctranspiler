cmake_minimum_required(VERSION 3.20)
project(scratchtocruntime C)

find_package(json-c CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_executable(scratchruntime output.c data.c runtime/scratch.c runtime/main.c runtime/motion.c runtime/looks.c runtime/operators.c runtime/renderer.c "runtime/renderer.h" "runtime/output.h" "runtime/main.h")

target_link_libraries(scratchruntime PRIVATE
    json-c::json-c
    SDL2::SDL2
    SDL2::SDL2main
)