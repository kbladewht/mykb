#pragma once


#define QF_ADC_PIN B0

#define LED_CAPS_LOCK_PIN A8
#define D_MODEL
#define USB_PIN_LED B15
#define WK_PIN C7

#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B14

#define QF_LED_COUNT 53

#undef RGBLED_NUM
#define RGBLED_NUM 53

#define POWER_PIN A3

#define MATRIX_ROWS 6
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { C8, C6, B13, B12, A6, C4 } //行1-6
#define MATRIX_COL_PINS { C10, C12, B3, B8, B9, B5, C0, C13 } //列1-8


#define SLEEP_SEC 8


#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28
