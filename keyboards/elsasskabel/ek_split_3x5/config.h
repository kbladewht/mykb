// Copyright 2022 ElsassKabel (@LucasCtrl)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x1999
#define PRODUCT_ID   0x3384
#define DEVICE_VER   0x0001
#define MANUFACTURER ElsassKabel
#define PRODUCT      Ek_Split_3x5

/* key matrix size */
// Rows are doubled
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6

#define TAPPING_TERM 200 // Duration (in ms) before key is considered on hold
#define DEBOUNCE 5

/* Configure commuhication between sides */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define BACKLIGHT_PIN D3
