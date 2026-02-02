cmake_minimum_required(VERSION 3.20)
project(scratchtoctranspiler C)

add_subdirectory(output)

find_package(json-c CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_executable(scratchcompiler src/main.c src/parsejson.c src/util.c src/buildccode.c)

target_link_libraries(scratchcompiler PRIVATE
    json-c::json-c
    SDL2::SDL2
    SDL2::SDL2main
)