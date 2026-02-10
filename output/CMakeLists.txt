cmake_minimum_required(VERSION 3.20)
project(scratchtocruntime C)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(SDL2-gfx CONFIG REQUIRED)

pkg_check_modules(RSVG REQUIRED IMPORTED_TARGET librsvg-2.0)
pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET cairo)
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64")
	set(LIBCO_BACKEND amd64.c)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86|i386|i686")
	set(LIBCO_BACKEND x86.c)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
	set(LIBCO_BACKEND aarch64.c)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
	set(LIBCO_BACKEND arm.c)
endif()

add_library(libco STATIC
	libco/libco.c
	libco/${LIBCO_BACKEND}
)

target_include_directories(libco PUBLIC libco)



add_executable(scratchruntime "runtime/main.h" "schedule_manager.c" "schedule_manager.h" "runtime/sound.c" "runtime/sound.h" "generated/sprite_data.c" "generated/output.c" runtime/scratch.c runtime/main.c runtime/motion.c runtime/looks.c runtime/operators.c runtime/renderer.c runtime/renderer.h   "runtime/control.c" "runtime/control.h" "generated/sprite_data.h" "runtime/sensing.c" "runtime/sensing.h" "runtime/data.c" "runtime/data.h" "runtime/pen.c" "runtime/pen.h" "generated/schedule.c" "runtime/schedule.h" "runtime/main.h" "schedule_manager.c" "schedule_manager.h" "runtime/sound.c" "runtime/sound.h")

target_link_libraries(scratchruntime PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2::SDL2_gfx
	SDL2_mixer::SDL2_mixer
	PkgConfig::RSVG
	PkgConfig::CAIRO
	PkgConfig::GLIB
	libco
)