cmake_minimum_required(VERSION 3.20)
project(scratchtocruntime C)

find_package(SDL2 CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(RSVG REQUIRED IMPORTED_TARGET librsvg-2.0)
pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo)
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)

add_executable(scratchruntime output.c "sprite_data.c" runtime/scratch.c runtime/main.c runtime/motion.c runtime/looks.c runtime/operators.c runtime/renderer.c runtime/renderer.h "runtime/output.h" "runtime/main.h" "runtime/control.c" "runtime/control.h" "sprite_data.h" "runtime/sensing.c" "runtime/sensing.h" "runtime/data.c" "runtime/data.h" "runtime/pen.c" "runtime/pen.h")

target_link_libraries(scratchruntime PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	PkgConfig::RSVG
	PkgConfig::CAIRO
	PkgConfig::GLIB

)