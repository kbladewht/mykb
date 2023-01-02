// Copyright 2022 ElsassKabel (@LucasCtrl)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
    /*
    * ,-----------------------------------------------------------------------------------------.
    * | ESC  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |   BACKSP   |
    * |-----------------------------------------------------------------------------------------|
    * |  TAB   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  ENTER   |
    * |-----------------------------------------------------------------------------------------|
    * |   SHIFT    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  FN  |
    * |-----------------------------------------------------------------------------------------'
    * |  CTRL  |   GUI    |  LALT  |    SPACE     |    BACKSP    |  RALT  |   GUI    |   CTRL   |
    * `-----------------------------------------------------------------------------------------'
    */
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(2),
        KC_LCTL, KC_LGUI,          KC_LALT, LT(1, KC_SPC),    KC_BSPC,          KC_RALT, KC_RGUI,          KC_RCTL
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS
    ),

    [2] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_DEL,           KC_TRNS, KC_TRNS,          KC_TRNS
    )
};
