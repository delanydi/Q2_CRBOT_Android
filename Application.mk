# Application.mk for CRBOT - Quad Touch Compatible Version
#
# This file specifies application-wide build settings for Android NDK
#
# Author: Manus AI
# Date: June 16, 2025
# Version: 1.0

# Target Android API level (minimum for Quad Touch compatibility)
APP_PLATFORM := android-16

# Target architectures (common Android ARM architectures)
APP_ABI := armeabi-v7a arm64-v8a

# Use GNU STL for better C++ compatibility
APP_STL := gnustl_static

# Enable C99 features
APP_CPPFLAGS := -std=c99

# Optimization level
APP_OPTIM := release

# Enable debugging symbols in release builds
APP_DEBUG := false

# Application name
APP_PROJECT_PATH := $(call my-dir)

# Build all modules
APP_MODULES := crbot

