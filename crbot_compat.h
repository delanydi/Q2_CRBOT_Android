/*
 * CRBOT Compatibility Header for Quad Touch (QT) Android
 * 
 * This header provides compatibility definitions for cross-platform
 * compilation, specifically targeting Android ARM architecture.
 * 
 * Author: Manus AI
 * Date: June 16, 2025
 * Version: 1.0
 */

#ifndef __CRBOT_COMPAT_H__
#define __CRBOT_COMPAT_H__

/* Compiler compatibility definitions */
#ifdef __GNUC__
    #define CRBOT_INLINE static inline
#elif defined(_MSC_VER)
    #define CRBOT_INLINE __inline
#else
    #define CRBOT_INLINE static
#endif

/* Platform-specific path separators */
#if defined(WIN32) || defined(_WIN32)
    #define PATHSEPERATOR_CHAR     '\\'
    #define PATHSEPERATOR_STR      "\\"
#else                       
    #define PATHSEPERATOR_CHAR     '/'
    #define PATHSEPERATOR_STR      "/"
#endif

/* Platform-specific includes */
#if defined(WIN32) || defined(_WIN32)
    #include <direct.h>
#else                       
    #include <sys/stat.h>
#endif

/* Android/ARM specific optimizations */
#ifdef __ARM_ARCH
    /* ARM-specific memory alignment considerations */
    #define CRBOT_ALIGN(x) __attribute__((aligned(x)))
    
    /* ARM NEON optimizations (if available) */
    #ifdef __ARM_NEON
        #include <arm_neon.h>
        #define CRBOT_NEON_AVAILABLE 1
    #else
        #define CRBOT_NEON_AVAILABLE 0
    #endif
#else
    #define CRBOT_ALIGN(x)
    #define CRBOT_NEON_AVAILABLE 0
#endif

/* Android NDK compatibility */
#ifdef __ANDROID__
    #include <android/log.h>
    #define CRBOT_ANDROID 1
    
    /* Android logging macros */
    #define CRBOT_LOG_TAG "CRBOT"
    #define CRBOT_LOGI(...) __android_log_print(ANDROID_LOG_INFO, CRBOT_LOG_TAG, __VA_ARGS__)
    #define CRBOT_LOGW(...) __android_log_print(ANDROID_LOG_WARN, CRBOT_LOG_TAG, __VA_ARGS__)
    #define CRBOT_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, CRBOT_LOG_TAG, __VA_ARGS__)
#else
    #define CRBOT_ANDROID 0
    #define CRBOT_LOGI(...) printf(__VA_ARGS__)
    #define CRBOT_LOGW(...) printf(__VA_ARGS__)
    #define CRBOT_LOGE(...) printf(__VA_ARGS__)
#endif

/* Math constants for ARM compatibility */
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/* Memory management helpers for Android */
#ifdef __ANDROID__
    /* Android-specific memory allocation tracking */
    void* crbot_malloc(size_t size);
    void crbot_free(void* ptr);
    #define CRBOT_MALLOC(size) crbot_malloc(size)
    #define CRBOT_FREE(ptr) crbot_free(ptr)
#else
    #define CRBOT_MALLOC(size) malloc(size)
    #define CRBOT_FREE(ptr) free(ptr)
#endif

#endif /* __CRBOT_COMPAT_H__ */

