LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := app
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES := jni.c hook.cpp ../../../src/app.cpp ../../../src/texture.cpp ../../../src/vector.cpp ../../../src/bubble.cpp ../../../src/background.cpp ../../../src/program.cpp
LOCAL_LDLIBS := -lGLESv2

include $(BUILD_SHARED_LIBRARY)
