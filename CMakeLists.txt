# CMakeLists.txt for CRBOT - Quad Touch Compatible Version
#
# Modern CMake build system for Android NDK compilation
# This provides an alternative to the Android.mk build system
#
# Author: Manus AI
# Date: June 16, 2025
# Version: 1.0

cmake_minimum_required(VERSION 3.10.2)

project(crbot)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler definitions for Android compatibility
add_definitions(-DANDROID)
add_definitions(-D__ANDROID__)
add_definitions(-Dstricmp=strcasecmp)

# Source files
set(CRBOT_SOURCES
    crbot_compat.c
    cr_main.c
    cr_menu.c
    g_ai.c
    g_chase.c
    g_cmds.c
    g_combat.c
    g_ctf.c
    g_func.c
    g_items.c
    g_main.c
    g_misc.c
    g_monster.c
    g_phys.c
    g_save.c
    g_spawn.c
    g_svcmds.c
    g_target.c
    g_trigger.c
    g_utils.c
    g_weapon.c
)

# Create shared library
add_library(crbot SHARED ${CRBOT_SOURCES})

# Compiler flags for optimization and ARM compatibility
target_compile_options(crbot PRIVATE
    -O3
    -ffast-math
    -funroll-loops
    -fomit-frame-pointer
    -fPIC
    -Wall
    -Wextra
)

# ARM-specific optimizations
if(ANDROID_ABI STREQUAL "armeabi-v7a")
    target_compile_options(crbot PRIVATE
        -mfpu=neon
        -mfloat-abi=softfp
    )
endif()

if(ANDROID_ABI STREQUAL "arm64-v8a")
    target_compile_options(crbot PRIVATE
        -march=armv8-a
    )
endif()

# Include directories
target_include_directories(crbot PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries
target_link_libraries(crbot
    log
    m
)

# Set output name and properties
set_target_properties(crbot PROPERTIES
    OUTPUT_NAME "crbot"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs/${ANDROID_ABI}"
)

# Install target for packaging
install(TARGETS crbot
    LIBRARY DESTINATION lib/${ANDROID_ABI}
)

