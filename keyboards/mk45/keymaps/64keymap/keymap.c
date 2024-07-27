#include QMK_KEYBOARD_H

#include "quantum.h"

#include "dynamic_keymap.h"
#include "uart.h"

#include "hal_pal.h"
#include "main_master.h"



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_ortho2_5x15(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RGB_TOG,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, MO(1), 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, KC_M, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT),

	[1] = LAYOUT_ortho2_5x15(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_NO, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, RGB_VAI, KC_M, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, RGB_MODE_FORWARD, RGB_VAD, RGB_MODE_REVERSE),

	[2] = LAYOUT_ortho2_5x15(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO,
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_NO, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_M, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_NO)

};


#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
{0,  1,  2,  3,  4,  5,  6,  NO_LED,},
{13,  12,  11,  10,  9,  8,  7,  NO_LED,},
{14,  15,  16,  17,  18,  19,  20,  21},
{29,  28,  27,  26,  25,  24,  23,  22},
{30,  31,  32,  33,  34,  35,  36,  37},
{44,  43,  42,  41,  NO_LED,   40,  39,  38},

    },
    {
      // LED Index to Physical Position
{0,64},{28,64},{56,64},{84,64},{112,64},{140,64},{168,64},
{0,51},{28,51},{56,51},{84,51},{112,51},{140,51},{168,51},     
{6,38},{42,38},{60,38},{88,38},{116,38},{144,38},{172,38}, {214,38},
{9,25},{49,25},{77,25},{105,25},{133,25},{161,25},{189,25}, {218,25},
{13,12},{56,12},{84,12},{112,12},{140,12},{168,12},{196,12}, {222,12},
{3,0},{34,0},{62,0},         {115,0},        {168,0},{196,0}, {222,0},
//U_RGB
{75,64},{150,64},
{0,42},{222,42},
{0,21},{222,21},
{75,0},{75,0},
    },
    {
      // LED Index to Flag
      4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4,
      //U_RGB
            2, 2,
         2,       2,
         2,       2,
            2, 2,
    }
};

 bool rgb_matrix_indicators_kb(void) {
     if (host_keyboard_led_state().caps_lock) {  // Capslock = RED
         rgb_matrix_set_color(28, 200, 0, 0);
     }
     return true;
 }
#endif


bool led_update_kb(led_t led_state) {

    bool res = led_update_user(led_state);
    if(res) {
        writePin(LED_CAPS_LOCK_PIN, led_state.caps_lock);
    }
    return res;
}
