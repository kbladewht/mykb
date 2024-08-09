MCU = STM32F401
BOARD = GENERIC_STM32_F401XC

KEYBOARD_SHARED_EP       = yes

BOOTLOADER = custom
FIRMWARE_FORMAT = uf2
UF2_FAMILY = 0xabcdf401
MCU_LDSCRIPT=QF_STM32F401


BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
ENCODER_ENABLE = no
UARTENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes        # Console for debug
NKRO_ENABLE = no          # Enable N-Key Rollover

SRC += ../../p401/actionuart.c
SRC += ../../p401/apiAdaper.c

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DQMK_MCU_STM32F401
OPT_DEFS += -DBOOTLOADER_TINYUF2
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = legacy
# VPATH += :../p401
VPATH += $(TOP_DIR)/keyboards/pivot/p401

messge_qf := tmplog
$(messge_qf): build
	@printf "*******************************\n"
	@printf "\033[0;32m Linked Pivot library *****\033[0m \n"
	@printf "\n************Done*******************"
all: $(messge_qf)

LDFLAGS += -Llib -lqf401
# LTO_ENABLE = yes
