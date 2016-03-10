LOCAL_PATH := $(call my-dir)
SRC_DIR := ../../../src

include $(CLEAR_VARS)

LOCAL_MODULE    := app
LOCAL_CFLAGS    := -Wall -Wextra
LOCAL_SRC_FILES := hook.cpp jni.c $(SRC_DIR)/app.cpp $(SRC_DIR)/texture.cpp $(SRC_DIR)/vector.cpp $(SRC_DIR)/bubble.cpp $(SRC_DIR)/background.cpp $(SRC_DIR)/program.cpp
LOCAL_LDLIBS := -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
