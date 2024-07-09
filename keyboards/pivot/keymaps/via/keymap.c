#include QMK_KEYBOARD_H

#include "quantum.h"

#include "dynamic_keymap.h"
#include "uart.h"
#include "outputselect.h"

#include "hal_pal.h"
#include "actionuart.h"

enum layers {
    CAP_KEY_LED_INDEX = 7,
    _FL
};


enum keyboard_keycodes {
    SHOW_LED_IND,              // delete current ble bound
    BLE_CLR,              // delete all ble bound
    NEW_SAFE_RANGE  // Important!
};

#define BL_SW_1     KC_F23  // 开启蓝牙通道1（需要打开蓝牙的条件下才行）
#define BL_SW_2     KC_F19  // 开启蓝牙通道2（需要打开蓝牙的条件下才行）
#define BL_SW_3     KC_F20  // 开启蓝牙通道3（需要打开蓝牙的条件下才行）


#define BAU_TOG     KC_F17  // 蓝牙和USB之间切换
#define BLE_DEL     KC_F22  // 删除当前蓝牙绑定
#define BLE_RESET     KC_F24  // 蓝牙reset,重新广播
#define MANU_SLEEP     KC_F18  //
#define ENABLE_AUTO_SWITCH     KC_F13  // 开启有线无线自动切换功能
#define USB_RST     KC_F16  //
#define HONG_USER     KC_F15  //
#define HONG_PWD     KC_F14  //
#define BL_DFU     KC_F21  //P



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = { \
    { QK_BOOT,  KC_1,   KC_2,   KC_3,   KC_4,      KC_5,   KC_6,  KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC}, \
    { KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,      KC_T,  KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS}, \
    { KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,      KC_G,  KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_NO}, \
    { KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,      KC_B,  KC_N,   KC_M,   KC_COMM,KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL}, \
    { KC_LCTL ,KC_LGUI,KC_LALT,KC_SPC, KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,  KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT} \
  },
 [1] = { \
   { KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,     KC_F5, KC_F6,  KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC}, \
    { QK_BOOT, BL_SW_1,BL_SW_2,BL_SW_3,   BLE_RESET, KC_T,  KC_Y,   KC_U,    KC_I,   KC_O,    KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS}, \
    { KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,      KC_G,  KC_H,   KC_J,    KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_WAKE, KC_NO}, \
    { KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,      KC_B,  KC_N,   KC_M,    KC_COMM,KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   BLE_DEL}, \
    { KC_LCTL ,KC_LGUI,KC_LALT,KC_SPC, KC_NO,     KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_LEFT,   KC_DOWN,   KC_RGHT} \
  }
};

void board_init(void) {
      setPinInputLow(HAND_WIRE_DETECT);
}


void Stm32_Rest2(void) {
    __set_FAULTMASK(1);
    NVIC_SystemReset();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {
        case BAU_TOG:
            if (record->event.pressed) {
                if (where_to_send() == OUTPUT_USB) {
                    set_output(OUTPUT_BLUETOOTH);
                     xprintf("Mode to BLE!!!\n");
                       // Stm32_Rest();
                } else {
                    set_output(OUTPUT_USB);
                    xprintf("Mode to USB!!!\n");
                }

                showPerChannel2();
            }
            return false;
       case USB_RST:
            if (record->event.pressed) {
                Stm32_Rest2();
            }
            return false;
        case BL_SW_1:
                if (record->event.pressed) {
                    channel_common(CHANNAL_001);
                     xprintf("0001\n");
                }
            return false;
        case BL_SW_2:
                if (record->event.pressed) {
                    channel_common(CHANNAL_002);
                }
            return false;
        case BL_SW_3:
                if (record->event.pressed) {
                    channel_common(CHANNAL_003);
                }
            return false;
         case BL_DFU:
                if (record->event.pressed) {
                    go_bl_dfu();
                }
            return false;
        case BLE_RESET:
            if (where_to_send() != OUTPUT_USB) {
                if (record->event.pressed) {
                    reset_current_BLE();
                }
            }
            return false;
        case BLE_DEL:
            if (where_to_send() != OUTPUT_USB) {
                if (record->event.pressed) {
                    unpair_current_BLE();
                }
            }
            return false;
         case HONG_USER:

                if (record->event.pressed) {
                    SEND_STRING_DELAY("hw72642\t",50);
                }
            return false;
         case HONG_PWD:

                if (record->event.pressed) {
                    SEND_STRING_DELAY("Kblade915\n",60);
                }
            return false;
        default:
            return true;
    }
    return true;
}


