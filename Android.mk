# Android.mk for CRBOT - Quad Touch Compatible Version
# 
# This makefile is designed for Android NDK compilation
# targeting ARM architectures for Quad Touch compatibility
#
# Author: Manus AI
# Date: June 16, 2025
# Version: 1.0

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Module name - this will create libcrbot.so
LOCAL_MODULE := crbot

# Source files
LOCAL_SRC_FILES := \
    crbot_compat.c \
    cr_main.c \
    cr_menu.c \
    g_ai.c \
    g_chase.c \
    g_cmds.c \
    g_combat.c \
    g_ctf.c \
    g_func.c \
    g_items.c \
    g_main.c \
    g_misc.c \
    g_monster.c \
    g_phys.c \
    g_save.c \
    g_spawn.c \
    g_svcmds.c \
    g_target.c \
    g_trigger.c \
    g_utils.c \
    g_weapon.c

# Compiler flags for Android/ARM compatibility
LOCAL_CFLAGS := \
    -DANDROID \
    -D__ANDROID__ \
    -Dstricmp=strcasecmp \
    -O3 \
    -ffast-math \
    -funroll-loops \
    -fomit-frame-pointer \
    -fPIC

# ARM-specific optimizations
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -mfpu=neon -mfloat-abi=softfp
    LOCAL_ARM_NEON := true
endif

ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_CFLAGS += -O3
endif

# Include directories
LOCAL_C_INCLUDES := $(LOCAL_PATH)

# Libraries to link against
LOCAL_LDLIBS := -llog -lm

# Build as shared library
include $(BUILD_SHARED_LIBRARY)

