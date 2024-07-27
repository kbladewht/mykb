#include QMK_KEYBOARD_H

#include "quantum.h"


#include "dynamic_keymap.h"
#include "uart.h"

#include "hal_pal.h"
#include "main_master.h"


#define BL_SW_1     KC_BLE_1
#define BL_SW_2     KC_BLE_2
#define BL_SW_3     KC_BLE_3  // RADIO
#define RADIO     KC_24_G  // RADIO

#define BLE_DEL     KC_BLE_DEL
#define BL_DFU     KC_BL_DFU  //
#define BAU_TOG     KC_F17
#define NKRO_GO     KC_F14  // GO NKRO
#define SIX_KEY_GO     KC_F15  // GO 6KEY



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = { \
    { QK_BOOT,   KC_NO,  KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,    KC_F8,  KC_F9,   KC_F10,   KC_F11,    KC_F12,       KC_PSCR,KC_SCRL, KC_PAUS}, \
    { KC_GRV,   KC_1,   KC_2,     KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,     KC_9,   KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,      KC_INS, KC_HOME, KC_PGUP}, \
    { KC_TAB,   KC_Q,   KC_W,     KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,      KC_NO,  KC_NO,   KC_NO}, \
    { KC_CAPS,  KC_A,   KC_S,     RGB_TOG,   KC_F17,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,    KC_NO,        KC_NO,  KC_NO,   KC_NO}, \
    { KC_LSFT,  KC_Z,   KC_X,     KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_NO,    KC_RSFT,   KC_NO,        KC_NO,  KC_UP,   KC_NO}, \
    { KC_LCTL,  KC_LGUI,KC_LALT,  KC_NO,  KC_NO,  KC_NO,  KC_SPC, KC_NO,  KC_NO,    KC_RALT,KC_RGUI, KC_APP,   KC_RCTL,   KC_NO,        KC_LEFT,KC_DOWN,KC_RGHT}
  },
 [1] = { \
    { QK_BOOT,  KC_NO,  KC_BLE_1,KC_BLE_2,KC_BLE_3,   KC_24_G,  KC_F5,  KC_F6,  KC_F7,    KC_F8,  KC_F9,   KC_F10,   KC_F11,    KC_F12,       KC_PSCR,KC_SCRL, KC_PAUS}, \
    { KC_GRV,   KC_1,   KC_2,     KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,     KC_9,   KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,      KC_INS, KC_HOME, KC_PGUP}, \
    { KC_BLE_DEL,   KC_Q,   KC_W,     KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,      KC_NO,  KC_NO,   KC_NO}, \
    { RGB_TOG,   KC_A,   KC_S,     KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,    KC_NO,        KC_NO,  KC_NO,   KC_NO}, \
    { KC_ADC_RGB_SHOW,  KC_Z,   KC_X,     KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_NO,    KC_RSFT,   KC_NO,        KC_NO,  KC_UP,   KC_NO}, \
    { KC_LCTL,  KC_LGUI,KC_LALT,  KC_NO,  KC_NO,  KC_NO,  KC_SPC, KC_NO,  KC_NO,    KC_RALT,KC_RGUI, KC_APP,   KC_RCTL,   KC_NO,        KC_LEFT,KC_DOWN,KC_RGHT}
  }
};


// void Stm32_Rest2(void) {
//     __set_FAULTMASK(1);
//     NVIC_SystemReset();
// }

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        { 0,    NO_LED,   1,    2,     3,     4,     5,      6,      7,      8,      9,     10,    11,    12,      13,   14,   15 },
        { 16,   17,    18,   19,    20,    21,    22,     23,     24,     25,     26,    27,    28,    29,      30,   31,   32 },
        { 33,   34,    35,   36,    37,    38,    39,     40,     41,     42,     43,    44,    45,    46,      NO_LED,  NO_LED,  NO_LED},
        { 47,   48,    49,   50,    51,    52,    53,     54,     55,     56,     57,    58,    59,    NO_LED,     NO_LED,  NO_LED,  NO_LED },
        { 60,   61,    62,   63,    64,    65,    66,     67,     68,     69,     70,    NO_LED,   71,    NO_LED,     NO_LED,  72,   NO_LED },
        { 73,   74,    75,   NO_LED,   NO_LED,   NO_LED,   76,     NO_LED,    NO_LED,    76,     78,    79,    80,    NO_LED,     81,   82,   83 }
    }, {
        // Key matrix (0 -> 63)
        {0  ,  0},               {26 ,  0},   {40 ,  0},   {54 ,  0},   {68 ,  0},     {82 ,  0},   {96 ,  0},   {110 ,  0}, {124,  0},  {138 ,  0}, {152,  0},   {168,  0},   {182,  0},   {196,  0}, {210,  0}, {223,  0},
        {0  ,  14},  {13 ,  14}, {26 ,  14},  {40 ,  14},  {54 ,  14},  {68 ,  14},  {82 ,  14},    {96 ,  14},  {110 , 14},  {124,  14}, {138 , 14}, {152, 14},  {168,  14},  {182, 14},   {196, 14}, {210, 14}, {223, 14},
        {0  , 26},   {13 ,  26}, {26 ,  26},  {40 ,  26},  {54 ,  26},  {68 ,  26},  {82 ,  26},    {96 ,  26},  {110 , 26},  {124,  26}, {138 , 26}, {152, 26},  {168,  26},  {182, 26},
        {0  , 38},   {13 ,  38}, {26 ,  38},  {40 ,  38},  {54 ,  38},  {68 ,  38},  {82 ,  38},    {96 ,  38},  {110 , 38},  {124,  38}, {138 , 38}, {152, 38},               {173, 38},
        {0  , 50},   {13 ,  50}, {26 ,  50},  {40 ,  50},  {54 ,  50},  {68 ,  50},  {82 ,  50},    {96 ,  50},  {110 , 50},  {124,  50},             {160, 50},               {179, 50},               {210, 50},
        {0  , 63},   {17 ,  63}, {31 ,  63},                                         {82 ,  63},                              {124,  63}, {142 , 63}, {168, 63},               {182, 63},   {196, 63},  {210, 63}, {223, 63},

}, {
        4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,          4,
        4, 4, 4,          4,         4, 4, 4, 4,     4, 4, 4,
    }
};

 bool rgb_matrix_indicators_kb(void) {
     if (host_keyboard_led_state().caps_lock) {  // Capslock = RED
         rgb_matrix_set_color(47, 200, 0, 0);
     }
     return true;
 }
#endif
