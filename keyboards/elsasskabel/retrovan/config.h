// Copyright 2022 ElsassKabel (@LucasCtrl)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x1999
#define PRODUCT_ID   0x3384
#define DEVICE_VER   0x0001
#define MANUFACTURER ElsassKabel
#define PRODUCT      RetroVan

/* key matrix size */
// Rows are doubled
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B4, B3, B2, B1 }
#define MATRIX_COL_PINS { C5, C4, C3, D0, C2, D1, C1, C0, D4, D6, D7, B0 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200 // Duration (in ms) before key is considered on hold
#define DEBOUNCE 5
