/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xFF, 0xCB, 0x4D, 0xFD, 0x58, 0x33, 0xC8, 0xA6}

// Esc + Enter. See: http://www.keyboard-layout-editor.com/#/gists/07a30619c76ab7d7be4932f94b3a7c06
#define VIAL_UNLOCK_COMBO_ROWS { 5, 8 }
#define VIAL_UNLOCK_COMBO_COLS { 2, 7 }

// https://docs.qmk.fm/#/squeezing_avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
