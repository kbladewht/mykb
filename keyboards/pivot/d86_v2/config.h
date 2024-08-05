#pragma once


// #define LED_CAPS_LOCK_PIN B15
#define LED_CAPS_LOCK_PIN C6
#define USB_PIN_LED B3
#define WK_PIN A15

#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT C15

#define POWER_PIN C13

#define QF_LED_COUNT 84

#undef RGBLED_NUM
#define RGBLED_NUM 84


#define QF_ADC_PIN C0
#define USE_VBAT

#define SLEEP_SEC 8


#define RADIO_LED_INDEX 46
#define BLE1_LED_INDEX 49
#define BLE2_LED_INDEX 48
#define BLE3_LED_INDEX 47

#define CAPS_LED_INDEX 36

#define CHARGE_DETECT_PIN B13
#define CHARGE_LED_PIN B14


#define MATRIX_ROWS 6
#define MATRIX_COLS 17

#define MATRIX_ROW_PINS     { A0, A1, A2, A3,  A4, A5}
#define MATRIX_COL_PINS     { C4, C5, B1 ,B2,  B7, \
                              B8, C10,C11,C12, B6, \
                              B5,B4,D2,  C3,C7,C9,C8}


// #define BLINK_BLE_LED
