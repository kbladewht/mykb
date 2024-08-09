MCU = STM32F401
BOARD = GENERIC_STM32_F401XC

USE_LIB_IND = Y
# This is use for building l4 for now , this can save building time.

ifeq ($(wildcard lib/libqf401.a),)
$(info libqf401.a not found , will build it by change USE_HAL_LIB_IND to N)
USE_LIB_IND = N
endif

ifeq ($(USE_LIB_IND),Y)
LDFLAGS += -Llib -lqf401
endif

include $(TOP_DIR)/keyboards/$(KEYBOARD_FOLDER_PATH_3)/p401/rules.mk
# LTO_ENABLE = yes
