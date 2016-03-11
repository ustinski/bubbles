#ifndef LOG

#ifdef __ANDROID__
#       include <android/log.h>
#       define LOG_TAG "SGM"
#       define LOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#else
#       include <cstdio>
#       define LOG(f, ...) printf(f "\n",##__VA_ARGS__)
#endif

#endif
