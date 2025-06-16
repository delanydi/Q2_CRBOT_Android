/*
 * CRBOT Android Compatibility Implementation
 * 
 * This file provides Android-specific implementations for memory management
 * and other platform-specific functionality.
 * 
 * Author: Manus AI
 * Date: June 16, 2025
 * Version: 1.0
 */

#include "crbot_compat.h"
#include <stdlib.h>
#include <string.h>

#ifdef __ANDROID__

/* Android-specific memory allocation tracking */
static size_t total_allocated = 0;
static size_t allocation_count = 0;

void* crbot_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        total_allocated += size;
        allocation_count++;
        CRBOT_LOGI("CRBOT: Allocated %zu bytes (total: %zu, count: %zu)", 
                   size, total_allocated, allocation_count);
    } else {
        CRBOT_LOGE("CRBOT: Failed to allocate %zu bytes", size);
    }
    return ptr;
}

void crbot_free(void* ptr) {
    if (ptr) {
        free(ptr);
        allocation_count--;
        CRBOT_LOGI("CRBOT: Freed memory (remaining allocations: %zu)", allocation_count);
    }
}

/* Android-specific initialization */
void crbot_android_init(void) {
    CRBOT_LOGI("CRBOT: Initializing Android compatibility layer");
    total_allocated = 0;
    allocation_count = 0;
}

/* Android-specific cleanup */
void crbot_android_cleanup(void) {
    CRBOT_LOGI("CRBOT: Cleaning up Android compatibility layer");
    if (allocation_count > 0) {
        CRBOT_LOGW("CRBOT: Warning - %zu allocations not freed", allocation_count);
    }
    if (total_allocated > 0) {
        CRBOT_LOGW("CRBOT: Warning - %zu bytes potentially leaked", total_allocated);
    }
}

/* Android-specific file path handling */
void crbot_get_android_path(const char* filename, char* fullpath, size_t maxlen) {
    /* For Android, we'll use the app's internal storage directory */
    /* This would typically be provided by the calling application */
    snprintf(fullpath, maxlen, "/data/data/com.opentouchgaming.quadtouch/files/%s", filename);
}

#endif /* __ANDROID__ */

/* Cross-platform utility functions */

/* Safe string copy with bounds checking */
void crbot_safe_strcpy(char* dest, const char* src, size_t destsize) {
    if (dest && src && destsize > 0) {
        strncpy(dest, src, destsize - 1);
        dest[destsize - 1] = '\0';
    }
}

/* Safe string concatenation with bounds checking */
void crbot_safe_strcat(char* dest, const char* src, size_t destsize) {
    if (dest && src && destsize > 0) {
        size_t destlen = strlen(dest);
        if (destlen < destsize - 1) {
            strncat(dest, src, destsize - destlen - 1);
        }
    }
}

/* Cross-platform path construction */
void crbot_build_path(char* result, size_t maxlen, const char* dir, const char* filename) {
    if (result && dir && filename && maxlen > 0) {
        snprintf(result, maxlen, "%s%s%s", dir, PATHSEPERATOR_STR, filename);
    }
}

