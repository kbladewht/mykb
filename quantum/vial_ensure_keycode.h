#pragma once

#include "quantum.h"
#include "via.h"

/*
 * This should contain all keycodes from keycodes.py
 * so that situations like https://github.com/qmk/qmk_firmware/issues/11157 don't happen
 */

/* KEYCODES_SPECIAL */
_Static_assert(KC_NO == 0, "");
_Static_assert(KC_TRNS == 1, "");

/* KEYCODES_BASIC */
/* (these should already never change, but just in case) */
_Static_assert(KC_A == 0x04, "");
_Static_assert(KC_B == 0x05, "");
_Static_assert(KC_C == 0x06, "");
_Static_assert(KC_D == 0x07, "");
_Static_assert(KC_E == 0x08, "");
_Static_assert(KC_F == 0x09, "");
_Static_assert(KC_G == 0x0A, "");
_Static_assert(KC_H == 0x0B, "");
_Static_assert(KC_I == 0x0C, "");
_Static_assert(KC_J == 0x0D, "");
_Static_assert(KC_K == 0x0E, "");
_Static_assert(KC_L == 0x0F, "");
_Static_assert(KC_M == 0x10, "");
_Static_assert(KC_N == 0x11, "");
_Static_assert(KC_O == 0x12, "");
_Static_assert(KC_P == 0x13, "");
_Static_assert(KC_Q == 0x14, "");
_Static_assert(KC_R == 0x15, "");
_Static_assert(KC_S == 0x16, "");
_Static_assert(KC_T == 0x17, "");
_Static_assert(KC_U == 0x18, "");
_Static_assert(KC_V == 0x19, "");
_Static_assert(KC_W == 0x1A, "");
_Static_assert(KC_X == 0x1B, "");
_Static_assert(KC_Y == 0x1C, "");
_Static_assert(KC_Z == 0x1D, "");
_Static_assert(KC_1 == 0x1E, "");
_Static_assert(KC_2 == 0x1F, "");
_Static_assert(KC_3 == 0x20, "");
_Static_assert(KC_4 == 0x21, "");
_Static_assert(KC_5 == 0x22, "");
_Static_assert(KC_6 == 0x23, "");
_Static_assert(KC_7 == 0x24, "");
_Static_assert(KC_8 == 0x25, "");
_Static_assert(KC_9 == 0x26, "");
_Static_assert(KC_0 == 0x27, "");
_Static_assert(KC_ENTER == 0x28, "");
_Static_assert(KC_ESCAPE == 0x29, "");
_Static_assert(KC_BSPACE == 0x2A, "");
_Static_assert(KC_TAB == 0x2B, "");
_Static_assert(KC_SPACE == 0x2C, "");
_Static_assert(KC_MINUS == 0x2D, "");
_Static_assert(KC_EQUAL == 0x2E, "");
_Static_assert(KC_LBRACKET == 0x2F, "");
_Static_assert(KC_RBRACKET == 0x30, "");
_Static_assert(KC_BSLASH == 0x31, "");
_Static_assert(KC_SCOLON == 0x33, "");
_Static_assert(KC_QUOTE == 0x34, "");
_Static_assert(KC_GRAVE == 0x35, "");
_Static_assert(KC_COMMA == 0x36, "");
_Static_assert(KC_DOT == 0x37, "");
_Static_assert(KC_SLASH == 0x38, "");
_Static_assert(KC_CAPSLOCK == 0x39, "");
_Static_assert(KC_F1 == 0x3A, "");
_Static_assert(KC_F2 == 0x3B, "");
_Static_assert(KC_F3 == 0x3C, "");
_Static_assert(KC_F4 == 0x3D, "");
_Static_assert(KC_F5 == 0x3E, "");
_Static_assert(KC_F6 == 0x3F, "");
_Static_assert(KC_F7 == 0x40, "");
_Static_assert(KC_F8 == 0x41, "");
_Static_assert(KC_F9 == 0x42, "");
_Static_assert(KC_F10 == 0x43, "");
_Static_assert(KC_F11 == 0x44, "");
_Static_assert(KC_F12 == 0x45, "");
_Static_assert(KC_PSCREEN == 0x46, "");
_Static_assert(KC_SCROLLLOCK == 0x47, "");
_Static_assert(KC_PAUSE == 0x48, "");
_Static_assert(KC_INSERT == 0x49, "");
_Static_assert(KC_HOME == 0x4A, "");
_Static_assert(KC_PGUP == 0x4B, "");
_Static_assert(KC_DELETE == 0x4C, "");
_Static_assert(KC_END == 0x4D, "");
_Static_assert(KC_PGDOWN == 0x4E, "");
_Static_assert(KC_RIGHT == 0x4F, "");
_Static_assert(KC_LEFT == 0x50, "");
_Static_assert(KC_DOWN == 0x51, "");
_Static_assert(KC_UP == 0x52, "");
_Static_assert(KC_NUMLOCK == 0x53, "");
_Static_assert(KC_KP_SLASH == 0x54, "");
_Static_assert(KC_KP_ASTERISK == 0x55, "");
_Static_assert(KC_KP_MINUS == 0x56, "");
_Static_assert(KC_KP_PLUS == 0x57, "");
_Static_assert(KC_KP_ENTER == 0x58, "");
_Static_assert(KC_KP_1 == 0x59, "");
_Static_assert(KC_KP_2 == 0x5A, "");
_Static_assert(KC_KP_3 == 0x5B, "");
_Static_assert(KC_KP_4 == 0x5C, "");
_Static_assert(KC_KP_5 == 0x5D, "");
_Static_assert(KC_KP_6 == 0x5E, "");
_Static_assert(KC_KP_7 == 0x5F, "");
_Static_assert(KC_KP_8 == 0x60, "");
_Static_assert(KC_KP_9 == 0x61, "");
_Static_assert(KC_KP_0 == 0x62, "");
_Static_assert(KC_KP_DOT == 0x63, "");
_Static_assert(KC_APPLICATION == 0x65, "");
_Static_assert(KC_KP_EQUAL == 0x67, "");
_Static_assert(KC_KP_COMMA == 0x85, "");
_Static_assert(KC_LCTRL == 0xE0, "");
_Static_assert(KC_LSHIFT == 0xE1, "");
_Static_assert(KC_LALT == 0xE2, "");
_Static_assert(KC_LGUI == 0xE3, "");
_Static_assert(KC_RCTRL == 0xE4, "");
_Static_assert(KC_RSHIFT == 0xE5, "");
_Static_assert(KC_RALT == 0xE6, "");
_Static_assert(KC_RGUI == 0xE7, "");

/* KEYCODES_SHIFTED */
_Static_assert(KC_TILD == 0x235, "");
_Static_assert(KC_EXLM == 0x21E, "");
_Static_assert(KC_AT == 0x21F, "");
_Static_assert(KC_HASH == 0x220, "");
_Static_assert(KC_DLR == 0x221, "");
_Static_assert(KC_PERC == 0x222, "");
_Static_assert(KC_CIRC == 0x223, "");
_Static_assert(KC_AMPR == 0x224, "");
_Static_assert(KC_ASTR == 0x225, "");
_Static_assert(KC_LPRN == 0x226, "");
_Static_assert(KC_RPRN == 0x227, "");
_Static_assert(KC_UNDS == 0x22D, "");
_Static_assert(KC_PLUS == 0x22E, "");
_Static_assert(KC_LCBR == 0x22F, "");
_Static_assert(KC_RCBR == 0x230, "");
_Static_assert(KC_LT == 0x236, "");
_Static_assert(KC_GT == 0x237, "");
_Static_assert(KC_COLN == 0x233, "");
_Static_assert(KC_PIPE == 0x231, "");
_Static_assert(KC_QUES == 0x238, "");
_Static_assert(KC_DQUO == 0x234, "");

/* KEYCODES_ISO */
_Static_assert(KC_NONUS_HASH == 0x32, "");
_Static_assert(KC_NONUS_BSLASH == 0x64, "");
_Static_assert(KC_RO == 0x87, "");
_Static_assert(KC_KANA == 0x88, "");
_Static_assert(KC_JYEN == 0x89, "");
_Static_assert(KC_HENK == 0x8A, "");
_Static_assert(KC_MHEN == 0x8B, "");
_Static_assert(KC_LANG1 == 0x90, "");
_Static_assert(KC_LANG2 == 0x91, "");

/* KEYCODES_LAYERS */
_Static_assert(FN_MO13 == 0x5F10, "");
_Static_assert(FN_MO23 == 0x5F11, "");

/* KEYCODES_QUANTUM */
_Static_assert(KC_GESC == 0x5C16, "");
_Static_assert(KC_LSPO == 0x5CD7, "");
_Static_assert(KC_RSPC == 0x5CD8, "");
_Static_assert(KC_LCPO == 0x5CF3, "");
_Static_assert(KC_RCPC == 0x5CF4, "");
_Static_assert(KC_LAPO == 0x5CF5, "");
_Static_assert(KC_RAPC == 0x5CF6, "");
_Static_assert(KC_SFTENT == 0x5CD9, "");

/* KEYCODES_BACKLIGHT */
_Static_assert(BL_TOGG == 23743, "");
_Static_assert(BL_STEP == 23744, "");
_Static_assert(BL_BRTG == 23745, "");
_Static_assert(BL_ON == 23739, "");
_Static_assert(BL_OFF == 23740, "");
_Static_assert(BL_INC == 23742, "");
_Static_assert(BL_DEC == 23741, "");
_Static_assert(RGB_TOG == 23746, "");
_Static_assert(RGB_MOD == 23747, "");
_Static_assert(RGB_RMOD == 23748, "");
_Static_assert(RGB_HUI == 23749, "");
_Static_assert(RGB_HUD == 23750, "");
_Static_assert(RGB_SAI == 23751, "");
_Static_assert(RGB_SAD == 23752, "");
_Static_assert(RGB_VAI == 23753, "");
_Static_assert(RGB_VAD == 23754, "");
_Static_assert(RGB_SPI == 23755, "");
_Static_assert(RGB_SPD == 23756, "");
_Static_assert(RGB_M_P == 23757, "");
_Static_assert(RGB_M_B == 23758, "");
_Static_assert(RGB_M_R == 23759, "");
_Static_assert(RGB_M_SW == 23760, "");
_Static_assert(RGB_M_SN == 23761, "");
_Static_assert(RGB_M_K == 23762, "");
_Static_assert(RGB_M_X == 23763, "");
_Static_assert(RGB_M_G == 23764, "");
_Static_assert(RGB_M_T == 23765, "");

/* KEYCODES_MEDIA */
_Static_assert(KC_F13 == 104, "");
_Static_assert(KC_F14 == 105, "");
_Static_assert(KC_F15 == 106, "");
_Static_assert(KC_F16 == 107, "");
_Static_assert(KC_F17 == 108, "");
_Static_assert(KC_F18 == 109, "");
_Static_assert(KC_F19 == 110, "");
_Static_assert(KC_F20 == 111, "");
_Static_assert(KC_F21 == 112, "");
_Static_assert(KC_F22 == 113, "");
_Static_assert(KC_F23 == 114, "");
_Static_assert(KC_F24 == 115, "");
_Static_assert(KC_PWR == 165, "");
_Static_assert(KC_SLEP == 166, "");
_Static_assert(KC_WAKE == 167, "");
_Static_assert(KC_EXEC == 116, "");
_Static_assert(KC_HELP == 117, "");
_Static_assert(KC_SLCT == 119, "");
_Static_assert(KC_STOP == 120, "");
_Static_assert(KC_AGIN == 121, "");
_Static_assert(KC_UNDO == 122, "");
_Static_assert(KC_CUT == 123, "");
_Static_assert(KC_COPY == 124, "");
_Static_assert(KC_PSTE == 125, "");
_Static_assert(KC_FIND == 126, "");
_Static_assert(KC_CALC == 178, "");
_Static_assert(KC_MAIL == 177, "");
_Static_assert(KC_MSEL == 175, "");
_Static_assert(KC_MYCM == 179, "");
_Static_assert(KC_WSCH == 180, "");
_Static_assert(KC_WHOM == 181, "");
_Static_assert(KC_WBAK == 182, "");
_Static_assert(KC_WFWD == 183, "");
_Static_assert(KC_WSTP == 184, "");
_Static_assert(KC_WREF == 185, "");
_Static_assert(KC_WFAV == 186, "");
_Static_assert(KC_BRIU == 189, "");
_Static_assert(KC_BRID == 190, "");
_Static_assert(KC_MPRV == 172, "");
_Static_assert(KC_MNXT == 171, "");
_Static_assert(KC_MUTE == 168, "");
_Static_assert(KC_VOLD == 170, "");
_Static_assert(KC_VOLU == 169, "");
_Static_assert(KC_MSTP == 173, "");
_Static_assert(KC_MPLY == 174, "");
_Static_assert(KC_MRWD == 188, "");
_Static_assert(KC_MFFD == 187, "");
_Static_assert(KC_EJCT == 176, "");
_Static_assert(KC_MS_U == 240, "");
_Static_assert(KC_MS_D == 241, "");
_Static_assert(KC_MS_L == 242, "");
_Static_assert(KC_MS_R == 243, "");
_Static_assert(KC_BTN1 == 244, "");
_Static_assert(KC_BTN2 == 245, "");
_Static_assert(KC_BTN3 == 246, "");
_Static_assert(KC_BTN4 == 247, "");
_Static_assert(KC_BTN5 == 248, "");
_Static_assert(KC_WH_U == 249, "");
_Static_assert(KC_WH_D == 250, "");
_Static_assert(KC_WH_L == 251, "");
_Static_assert(KC_WH_R == 252, "");
_Static_assert(KC_ACL0 == 253, "");
_Static_assert(KC_ACL1 == 254, "");
_Static_assert(KC_ACL2 == 255, "");
_Static_assert(KC_LCAP == 130, "");
_Static_assert(KC_LNUM == 131, "");
_Static_assert(KC_LSCR == 132, "");

/* KEYCODES_MACRO */
_Static_assert(MACRO00 == 0x5F12, "");
_Static_assert(MACRO01 == 0x5F13, "");
_Static_assert(MACRO02 == 0x5F14, "");
_Static_assert(MACRO03 == 0x5F15, "");
_Static_assert(MACRO04 == 0x5F16, "");
_Static_assert(MACRO05 == 0x5F17, "");
_Static_assert(MACRO06 == 0x5F18, "");
_Static_assert(MACRO07 == 0x5F19, "");
_Static_assert(MACRO08 == 0x5F1A, "");
_Static_assert(MACRO09 == 0x5F1B, "");
_Static_assert(MACRO10 == 0x5F1C, "");
_Static_assert(MACRO11 == 0x5F1D, "");
_Static_assert(MACRO12 == 0x5F1E, "");
_Static_assert(MACRO13 == 0x5F1F, "");
_Static_assert(MACRO14 == 0x5F20, "");
_Static_assert(MACRO15 == 0x5F21, "");
