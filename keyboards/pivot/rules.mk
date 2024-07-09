
# MCU name
#MCU = STM32F401


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
COMMAND_ENABLE = no        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality

RGBLIGHT_ENABLE = no    # Enable keyboard RGB underglow
WS2812_DRIVER = pwm
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812

SRC += quantum/midi/bytequeue/bytequeue.c
SRC += quantum/midi/bytequeue/interrupt_setting.c

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

SRC += rtt_viewer/SEGGER_RTT_printf.c
SRC += rtt_viewer/SEGGER_RTT.c


# SRC += chthreads.c

