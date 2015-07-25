LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := main
LOCAL_SRC_FILES := main.c
LOCAL_CFLAGS    += -pie -fPIE
LOCAL_LDFLAGS   += -pie -fPIE
include $(BUILD_EXECUTABLE)